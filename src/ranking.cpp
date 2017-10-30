/** @author /u/exegete_ */
/** Revised 01 Oct 2017 */

#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
using namespace std;

/* http://stackoverflow.com/questions/5056645/sorting-stdmap-using-value */
template<typename A, typename B>
std::pair<B,A> flip_pair(const std::pair<A,B> &p) 
{
    return std::pair<B,A>(p.second, p.first);
}

/* http://stackoverflow.com/questions/5056645/sorting-stdmap-using-value */
template<typename A, typename B>
std::multimap<B,A> flip_map(const std::map<A,B> &src) 
{
    std::multimap<B,A> dst;
    std::transform(src.begin(), src.end(), std::inserter(dst, dst.begin()), 
                   flip_pair<A,B>);
    return dst;
}

void output(multimap<double,string> &score_avg_sorted, string outfile, string csvfile, map<string,string> &pretty_name, map <string,string> &flair, map <string,int> &wins, map <string,int> &losses);

int main(int argc, char *argv[]) 
{

    bool shuffle_records;
	bool winner_is_FBS;
	bool loser_is_FBS;
	double score_avg_prev;
	int loser_rank;
	int new_loser_rank;
	int new_winner_rank;
	int winner_rank;
	map <string, double> score_avg;
	map <string, int> wins;
	map <string, int> losses;
	map <string, int> games;
	map <string, double> score_avg_tot;
	multimap<double,string> score_avg_sorted;
	ofstream oFS;
	string team;
	string winner;
	string loser;
	string record;
    vector <double> score;
	vector <string> teams;
	vector <string> records;

	if (argc != 2) 
	{
		cout << "ERROR: First command line argument must be configuration file." << endl;
		return -1;
	}

	boost::property_tree::ptree pt;
	boost::property_tree::ini_parser::read_ini(argv[1], pt);

	const string teamsfile = pt.get<std::string>("Input.teamsfile");
	const string winslossfile = pt.get<std::string>("Input.recordsfile");

	const string outfile = pt.get<std::string>("Output.resultsfile");
	const string csvfile = pt.get<std::string>("Output.csvfile");

	const string shuffle_records_str = pt.get<std::string>("Advanced.shuffle_records","true");
    if (shuffle_records_str == "true")
    {
        shuffle_records = true;
    }
    else if  (shuffle_records_str == "false")
    {
        shuffle_records = false;
    }
    else
    {
		cout << "ERROR: 'Advanced.shuffle_records' must be 'true' or 'false'." << endl;
		return -1;
    }

	char *endptr;

	const int log_freq = strtol(pt.get<std::string>("Output.log_freq","1000").c_str(), &endptr, 10);
	if (*endptr != ' ' && *endptr != 0)
	{
		cout << "ERROR: 'Output.log_freq' must be an integer." << endl;
		return -1;
	}

	const int weeks = strtol(pt.get<std::string>("Input.weeks").c_str(), &endptr, 10);
	if (*endptr != ' ' && *endptr != 0)
	{
		cout << "ERROR: 'weeks' must be an integer." << endl;
		return -1;
	}

	const double tol = strtod(pt.get<std::string>("Advanced.tol","1e-6").c_str(), &endptr);
	if (*endptr != ' ' && *endptr != 0)
	{
		cout << "ERROR: 'Advanced.tol' must be a real number." << endl;
		return -1;
	}
	const int max_iter = strtol(pt.get<std::string>("Advanced.max_iter","10000000").c_str(), &endptr, 10);
	if (*endptr != ' ' && *endptr != 0)
	{
		cout << "ERROR: 'Advanced.max_iter' must be an integer." << endl;
		return -1;
	}

	cout << "Reading teams from: " << teamsfile << endl;
	cout << "Reading records from: " << winslossfile << endl;
	cout << "Ranking will be output to: " << csvfile << endl;
	cout << "Log frequency: " << log_freq << endl;
	cout << "Tolerance: " << tol << endl;
	cout << "Max iterations: " << max_iter << endl;

	istringstream linestream;
	map <string,string> flairs;
	map <string,string> pretty_name;
	string flair;
	string line;
	string name;

	/* Read in and store the FBS teams from a file */
	ifstream iFS(teamsfile.c_str());

	while(getline(iFS,line)) 
	{
		linestream.clear();
		linestream.str(line);
        getline(linestream, team, ',');
        getline(linestream, name, ',');
        getline(linestream, flair);
        teams.push_back(team);
        pretty_name[team] = name;
        flairs[team] = flair;
        score_avg[team] = 0.0;
        wins[team] = 0;
        losses[team] = 0;
        games[team] = 0;
        score_avg_tot[team] = 0.0;
	}

	iFS.close();

	const int teams_n = teams.size();
	cout << "Number of teams: " << teams_n << endl;

	/* Read in and store win-loss records. */
	iFS.open(winslossfile.c_str());
	while (!iFS.eof()) 
	{
		getline(iFS >> ws,record);
		if (iFS.eof()) 
		{	
			break;
		}
        if (record.at(0) != '#') {
            records.push_back(record);

            /* Save wins / losses for output */
            linestream.clear();
            linestream.str(record);
            getline(linestream, winner, ',');
            getline(linestream, loser);
            wins[winner]++;
            losses[loser]++;
        }
	}

	iFS.close();

    for (int j = 0; j < teams_n; j++) 
    {
        games[teams.at(j)] = wins[teams.at(j)] + losses[teams.at(j)];
        if (games[teams.at(j)] == 0) cout << "WARNING: No games played for " << teams.at(j) << endl;
    }

	const int records_n = records.size();
	cout << "Number of games: " << records_n << endl;

    oFS.open("non-FBS.txt");
    oFS << "NOTE: The following teams were not found in the teams file and thus are considered non-FBS teams:" << endl;
    for (int record_i = 0; record_i < records_n; record_i++)
    {

        linestream.clear();
        linestream.str(records.at(record_i));
        getline(linestream, winner, ',');
        getline(linestream, loser);

        winner_is_FBS = false;
        loser_is_FBS = false;
        for (int j = 0; j < teams_n; j++) 
        {
            if (teams.at(j) == winner) 
            {
                winner_is_FBS = true;
            }
            if (teams.at(j) == loser) 
            {
                loser_is_FBS = true;
            }
        }

        if (!winner_is_FBS)
        {
            oFS << winner << endl;
        }

        if (!loser_is_FBS)
        {
            oFS << loser << endl;
        }
    }
    oFS.close();

	/* MAIN ALGORITHM */

	int iter;

	for (int i = 0; i < teams_n; i++) 
	{
        score.push_back(1.0 - (double)i/(double)teams_n);
		score_avg[teams.at(i)] = 0.0;
	}
	score_avg_prev = 0.0;

	iter = 0;
	double test = 1000.0;

    cout << "Beginning calculation..." << endl;
    while (test > tol && iter < max_iter)
    {
        /* Randomly shuffle the preseason rankings. */
        random_shuffle(teams.begin(), teams.end());

        /* Randomly shuffle the records for the year. */
        if (shuffle_records)
        {
            random_shuffle(records.begin(), records.end());
        }

        /* Cycle through all of the records */
        for (int record_i = 0; record_i < records_n; record_i++)
        {

            /* Get winner and loser for this record */
            linestream.clear();
            linestream.str(records.at(record_i));
            getline(linestream, winner, ',');
            getline(linestream, loser);

            /* Find out the rank of the winner and loser in this random
             * permutation. Also find out if the winner and loser are both FBS
             * teams. */
            winner_is_FBS = false;
            loser_is_FBS = false;
            winner_rank = -1;
            loser_rank = -1;
            for (int j = 0; j < teams_n; j++) 
            {
                if (teams.at(j) == winner) 
                {
                    winner_rank = j; 
                    winner_is_FBS = true;
                }
                if (teams.at(j) == loser) 
                {
                    loser_rank = j;
                    loser_is_FBS = true;
                }

            }

            /* 
             * If both teams are FBS and the loser is more highly
             * ranked than the winner, the loser moves down and the
             * winner moves up. You can only move up or down the
             * maximum offset which is the number of teams divided by
             * the number of games you've played. You can't move up
             * higher than number 1, and you can't be lower than the
             * number of teams. If you play an FCS team and lose you
             * go down an offset equal to the number teams divided by
             * the number of games you've played.
             */
            if (loser_is_FBS && winner_is_FBS && winner_rank > loser_rank) 
            {
                new_loser_rank = min(loser_rank + (winner_rank - loser_rank)/weeks, teams_n-1);
                new_winner_rank = max(winner_rank - (winner_rank - loser_rank)/weeks, 0);

                teams.erase(remove(teams.begin(), teams.end(), loser), teams.end());
                teams.insert(teams.begin()+new_loser_rank,loser);

                teams.erase(remove(teams.begin(), teams.end(), winner), teams.end());
                teams.insert(teams.begin()+new_winner_rank,winner);

            }
            else if (loser_is_FBS && (!winner_is_FBS))
            {
                new_loser_rank = min(loser_rank + teams_n / weeks, teams_n-1);

                teams.erase(remove(teams.begin(), teams.end(), loser), teams.end());
                teams.insert(teams.begin()+new_loser_rank,loser);
            }
        }

        test = 0.0;
        /* Save the results from this permutation */
        for (int j = 0; j < teams_n; j++) 
        {
            score_avg_prev = score_avg[teams.at(j)];
            score_avg[teams.at(j)] += score[j];
            test += pow( score_avg[teams.at(j)]/((double)(iter+1)) - score_avg_prev/((double)iter), 2);
        }
        test = sqrt(test);
        if (iter == 0)
        {
            test = 1000.0;
        }

        if (iter % log_freq == 0)
        {
            cout << "Iter: " << iter << " Diff: " << test << endl;
        }

        iter++;
        
    }

    if (iter < max_iter)
    {
        cout << "This calculation has converged in " << iter << " iterations!" << endl;
    }
    else
    {
        cout << "Could not achieve convergence after " << iter << " iterations." << endl;
    }
    cout << "Tolerance: " << tol << endl;
    cout << "Difference: " << test << endl;

    /* Normalization */
    for (int i = 0; i < teams_n; i++) 
    {
        score_avg[teams.at(i)] /= ((double)iter);
    }

    score_avg_sorted = flip_map(score_avg);
    output(score_avg_sorted, outfile, csvfile, pretty_name, flairs, wins, losses);

	return 0;
}

void output(multimap<double,string> &score_avg_sorted, string outfile, string csvfile, map<string,string> &pretty_name, map <string,string> &flair, map <string,int> &wins, map <string,int> &losses)
{
	ofstream oFS;
	vector <string> team;
	vector <double> score;

	/* Retrieve the keys from the iterator   
	 * http://stackoverflow.com/questions/110157/how-to-retrieve-all-keys-or-values-from-a-stdmap */
	for (map<double,string>::iterator it=score_avg_sorted.begin(); it != score_avg_sorted.end(); ++it) 
	{
		team.push_back(it->second);
		score.push_back(it->first);
	}

	/* Reddit-formatted output */
	oFS.open(outfile.c_str());
	oFS << fixed << setprecision(6);
	//oFS << " **Rank** | [/r/CFB](#l/rcfb)                        | **Team**                  | **Record** | **Score**  " << endl;
	//oFS << "----------|------------------------------------------|---------------------------|------------|------------" << endl;
	oFS << " **Rank** |  |**Team**                  | **Record** | **Score**  " << endl;
	oFS << "----------|--|---------------------------|------------|------------" << endl;
	for (unsigned int i = team.size()-1; i >= team.size()-25; i--)
	{
		oFS << setw(9)  << left << team.size()-i << " | ";
		//oFS << setw(40) << left << flair[team[i]] << " | ";
		oFS << left << "![" << pretty_name[team[i]] << "](logos/" << team[i] << ".png) | "; 
		oFS << setw(25) << left <<pretty_name[team[i]] << " | " ;
		oFS << setw(2) << right << wins[team[i]] << left << "-" << setw(7) << left << losses[team[i]] << " | " ;
		oFS << setw(10) << right << score[i];
		oFS << endl;
	}
	oFS.close();
	cout << "Top 25 stored in " << outfile << "." << endl;

	/* CSV Output */
	oFS.open(csvfile.c_str());
	oFS << fixed << setprecision(6);
	oFS << "rank,team,record,score" << endl;
	for (int i = team.size()-1; i >= 0; i--)
	{
		oFS << team.size()-i << "," << pretty_name[team[i]] << "," << wins[team[i]] << "-" << losses[team[i]] << "," << score[i] << endl;
	}
	oFS.close();
	cout << "Ranking completed and stored in " << csvfile << "." << endl;

	return;
}
