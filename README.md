# CFB Rankings

After 6 weeks of play in the 2017-2018 season:

 **Rank** |  | **Team**                  | **Record** | **Score**  
----------|--|---------------------------|------------|------------
1 | ![Clemson](logos/clemson.png) | Clemson                   |  6-0       |   0.660281
2 | ![Alabama](logos/alabama.png) | Alabama                   |  6-0       |   0.658990
3 | ![Penn State](logos/penn-st.png) | Penn State                |  6-0       |   0.654374
4 | ![Georgia](logos/georgia.png) | Georgia                   |  6-0       |   0.643268
5 | ![Washington State](logos/washington-st.png) | Washington State          |  6-0       |   0.634279
6 | ![San Diego State](logos/san-diego-st.png) | San Diego State           |  6-0       |   0.633303
7 | ![Wisconsin](logos/wisconsin.png) | Wisconsin                 |  5-0       |   0.632940
8 | ![Washington](logos/washington.png) | Washington                |  6-0       |   0.631693
9 | ![Navy](logos/navy.png) | Navy                      |  5-0       |   0.630978
10 | ![TCU](logos/tcu.png) | TCU                       |  5-0       |   0.620709
11 | ![UCF](logos/ucf.png) | UCF                       |  4-0       |   0.618785
12 | ![USC](logos/southern-california.png) | USC                       |  5-1       |   0.615849
13 | ![Notre Dame](logos/notre-dame.png) | Notre Dame                |  5-1       |   0.611020
14 | ![Ohio State](logos/ohio-st.png) | Ohio State                |  5-1       |   0.609660
15 | ![South Florida](logos/south-fla.png) | South Florida             |  5-0       |   0.603718
16 | ![Miami (FL)](logos/miami-fl.png) | Miami (FL)                |  4-0       |   0.596231
17 | ![North Carolina State](logos/north-carolina-st.png) | North Carolina State      |  5-1       |   0.594612
18 | ![Michigan State](logos/michigan-st.png) | Michigan State            |  4-1       |   0.593930
19 | ![Michigan](logos/michigan.png) | Michigan                  |  4-1       |   0.590256
20 | ![Kentucky](logos/kentucky.png) |  Kentucky                  |  5-1       |   0.589251
21 | ![Houston](logos/houston.png) | Houston                   |  4-1       |   0.588445
22 | ![Oklahoma State](logos/oklahoma-st.png) | Oklahoma State            |  4-1       |   0.587536
23 | ![Auburn](logos/auburn.png) | Auburn                    |  5-1       |   0.586956
24 | ![Virginia Tech](logos/virginia-tech.png) | Virginia Tech             |  5-1       |   0.586676
25 | ![Oklahoma](logos/oklahoma.png) | Oklahoma                  |  4-1       |   0.581508

[Full rankings](output/rankings.csv)

## About

This is a simple resume-based algorithm I developed for ranking college football
teams. It just uses wins and losses.

* Preaseason rankings can bias a poll's effectiveness. To overcome
  this, this algorithm uses randomly generated preaseason rankings. 
* In most polls a recent win tends to be counted more favorably than
  earlier wins. This algorithm randomly shuffles the records of all
  games in order to alleviate this problem.
* Only wins and losses are counted in the algorithm
  (see below).  Strength of schedule is built in, because winning against a team
  ranked higher in an iteration moves your team up.

## Running

First scrape the win/loss records by doing:

    $ python extra/scrapeRecords.py

Review any messages indicating not all games have been played for the
week. `gameStatus` should equal `FINAL` when a game has been
completed. Sometimes games are postponed, and that will be indicated
by a message as well but can be safely ignored. Rankings are by
default stored in `data/rankings.txt` and are simply a list of winners
comma separated with their respective losers.

Then compile the main program if you have not already done so:

    $ make

From there run the program:

    $ ./run data/config.in

The output by default will be in `output/rankings.txt` and
`output/rankings.csv`. Note there is also a file named `non-FBS.txt`
that is output. Review to see if there are any FBS teams in the file
by mistake. If so, `data/teams.txt` needs to be adjusted with the
correct name to match up with what is being pulled from NCAA.com.

## Algorithm

The following process is run until the difference between two iterations is less
than some tolerance (default 1e-6). It uses all data (wins-losses) for the
current season to get the team's average score.

1. A preseason ranking of all FBS teams is randomly generated. 
2. The records of each game (who won and who lost) are randomly shuffled.
3. Each record is then treated one by one. 
a. If a team wins against a lower ranked team, nothing happens.
b. If a team wins against a higher ranked team, the higher team moves
down and the lower teams moves up. The higher team
moves down the difference in ranks divided by the number of games they
have played; the lower team moves up the difference in rank divided
the number of games they have played.
c. If a team loses to an FCS team, it moves down the total number of
FBS teams divided by this factor.
4. After the above movement occurs for all weeks, the rankings for
   this iteration are saved as a score. The score = 1 -
ranking/nteams.

After the above process converges to within the tolerance, the average scores
are calculated (score / iterations) and teams are ranked by their average
scores.

