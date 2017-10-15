# CFB Rankings

This is a simple resume-based algorithm I developed for ranking college football
teams. It just uses wins and losses.

* Preaseason rankings can bias a poll's effectiveness. To overcome
  this, this algorithm uses randomly generated preaseason rankings. 
* In most polls a recent win or loss tends to be counted more strongly than
  earlier wins. This algorithm randomly shuffles the records of all
  games in order to alleviate this problem.
* Only wins and losses are counted in the algorithm
  (see below).  Strength of schedule is built in, because winning against a team
  ranked higher in an iteration moves your team up.

See [`docs/about.md`](docs/about.md) for more information on how to
compile the program and how the algorithm works. 

## Current rankings

After 7 weeks of play in the 2017-2018 season:

[Full rankings](output/rankings.csv)

 **Rank** |  | **Team**                  | **Record** | **Score** | **AP** | **Diff**
----------|--|-------------------------|------------|------------|--|--
1 | ![Alabama](logos/alabama.png) |  Alabama                                        |  7-0       |   0.656094 | 1 | 0
2 | ![Georgia](logos/georgia.png) |  Georgia                                        |  7-0       |   0.639660 | 3 | -1
3 | ![Penn State](logos/penn-st.png) |  Penn State                                  |  6-0       |   0.635700 | 2 | 1
4 | ![Wisconsin](logos/wisconsin.png) |  Wisconsin                                  |  6-0       |   0.633779 | 5 | -1
5 | ![TCU](logos/tcu.png) |  TCU                                                    |  6-0       |   0.623445 | 4 | 1
6 | ![USC](logos/southern-california.png) |  USC                                    |  6-1       |   0.619119 | 11 | -5
7 | ![Clemson](logos/clemson.png) |  Clemson                                        |  6-1       |   0.617413 | 7 | 0
8 | ![UCF](logos/ucf.png) |  UCF                                                    |  5-0       |   0.616993 | 20 | -12
9 | ![Ohio State](logos/ohio-st.png) |  Ohio State                                  |  6-1       |   0.613780 | 6 | 3
10 | ![South Florida](logos/south-fla.png) |  South Florida                         |  6-0       |   0.606025 | 16 | -5
11 | ![Miami (FL)](logos/miami-fl.png) |  Miami (FL)                                |  5-0       |   0.603985 | 8 | 3
12 | ![Michigan State](logos/michigan-st.png) |  Michigan State                     |  5-1       |   0.601154 | 18 | -6
13 | ![North Carolina State](logos/north-carolina-st.png) |  North Carolina State   |  6-1       |   0.601148 | 16 | -3
14 | ![Michigan](logos/michigan.png) |  Michigan                                    |  5-1       |   0.598193 | 19 | -5
15 | ![San Diego State](logos/san-diego-st.png) |  San Diego State                  |  6-1       |   0.597598 | 26 | -11
16 | ![Notre Dame](logos/notre-dame.png) |  Notre Dame                              |  5-1       |   0.597356 | 13 | 3
17 | ![Washington](logos/washington.png) |  Washington                              |  6-1       |   0.594634 | 12 | 5
18 | ![Navy](logos/navy.png) |  Navy                                                |  5-1       |   0.594476 | 35 | -17
19 | ![Washington State](logos/washington-st.png) |  Washington State               |  6-1       |   0.594250 | 15 | 4
20 | ![Oklahoma](logos/oklahoma.png) |  Oklahoma                                    |  5-1       |   0.591778 | 9 | 11
21 | ![Oklahoma State](logos/oklahoma-st.png) |  Oklahoma State                     |  5-1       |   0.590952 | 10 | 11
22 | ![Marshall](logos/marshall.png) |  Marshall                                    |  5-1       |   0.586148 | 38 | -16
23 | ![Memphis](logos/memphis.png) |  Memphis                                       |  5-1       |   0.582925 | 25 | -2
24 | ![Stanford](logos/stanford.png) |  Stanford                                    |  5-2       |   0.581243 | 22 | 2
25 | ![Kentucky](logos/kentucky.png) |  Kentucky                                    |  5-1       |   0.577906 | 30 | -5

Here are teams in the AP Poll but not in the top 25 of this computer
poll:

 **Rank** |  | **Team**                  | **Record** | **Score** | **AP** | **Diff**
----------|--|-------------------------|------------|------------|--|--
27 | ![Virginia Tech](logos/virginia-tech.png) | Virginia Tech | 5-1        |  0.575602 | 14 | 13
33 | ![LSU](logos/lsu.png) |  LSU               |  5-2       |  0.556034 | 24 | 9
34 | ![Auburn](logos/auburn.png) |  Auburn      |  5-2       |  0.554768 | 21 | 13
49 | ![West Virginia](logos/west-virginia.png) | West Virginia | 4-2 | 0.534089 | 23 | 16

Teams most over-ranked by AP:

![West Virginia](logos/west-virginia.png) ![Auburn](logos/auburn.png) ![Virginia Tech](logos/virginia-tech.png) ![Oklahoma](logos/oklahoma.png) ![Oklahoma State](logos/oklahoma-st.png) ![LSU](logos/lsu.png)

Teams most under-ranked by AP:

![Navy](logos/navy.png) ![Marshall](logos/marshall.png) ![UCF](logos/ucf.png) ![San Diego State](logos/san-diego-st.png) ![Michigan State](logos/michigan-st.png)

*Note*: These results do not include the Akron-W. Michigan game, yet to be played on October 15, 2017.
