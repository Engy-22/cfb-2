# Author: /u/exegete_
# Revised: 20 Sept 2017
# This scrapes the records of FBS teams from the NCAA website.

from lxml import html
import requests
import sys
import time

def doScraping(f,year,week):

    strweek = week
    if week != "P":
        if int(week) < 10:
            strweek = "0" + week

    f.write("# {0} Week {1}\n".format(year, week))

    SCHEDURLBASE = "http://www.ncaa.com/scoreboard/football/fbs/"
    SCHEDURL = SCHEDURLBASE + str(year) + "/" + strweek
    print("Getting results for week " + str(week) + " from " + SCHEDURL + ".")

    schedpage = requests.get(SCHEDURL)
    schedtree = html.fromstring(schedpage.text)
    schedteams = schedtree.xpath('//div[@class="team"]//a/@href')
    for y in range(0,len(schedteams)):
        schedteams[y] = schedteams[y][9:]

    finalscores = schedtree.xpath('//td[@class="final score"]/text()')
    if len(finalscores) == 0:
        print("No scores for week " + week + ". Exiting.")
        sys.exit()
        return

    gameStatus = schedtree.xpath('//div[starts-with(@class,"game-status")]/text()')
    x = 0
    games_not_yet_played = 0
    games_canceled = 0
    for y in range(0,len(schedteams)-1,2):
        status = gameStatus[int(y/2)]
        if ("Final" in status):
            # Team with higher score is the winner and is written first to the
            # record
            if int(finalscores[x]) > int(finalscores[x+1]):
                f.write(schedteams[y].rstrip()+',')
                f.write(schedteams[y+1].rstrip()+'\n')
            else:
                f.write(schedteams[y+1].rstrip()+',')
                f.write(schedteams[y].rstrip()+'\n')
            x += 2
        elif (":" in status and " ET" in status):
            games_not_yet_played = games_not_yet_played + 1
        elif ("canceled" in status or "postponed" in status):
            games_canceled = games_canceled + 1
        else:
            print("ERROR: gameStatus = {0}".format(gameStatus[int(y/2)]))

    if games_not_yet_played > 0:
        if games_not_yet_played == 1:
            print("WARNING: {0} game not yet played for week {1}.".format(games_not_yet_played,week))
        else:
            print("WARNING: {0} games not yet played for week {1}.".format(games_not_yet_played,week))

    if games_canceled > 0:
        if games_canceled == 1:
            print("NOTE: {0} game canceled or postponed for week {1}.".format(games_canceled,week))
        else:
            print("NOTE: {0} games canceled or postponed for week {1}.".format(games_canceled,week))

    time.sleep(2)

weeks = 9;
year = 2017;
f = open("data/record.txt","w")
for week in range(1,weeks+1):
    doScraping(f,year,str(week))

f.close();
