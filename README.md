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

See `[docs/about.md](docs/about.md)` for more information on how to
compile the program and how the algorithm works. 


After 7 weeks of play in the 2017-2018 season:

 **Rank** |  | **Team**                  | **Record** | **Score**  
----------|--|-------------------------|------------|------------
1 | ![Alabama](logos/alabama.png) |  Alabama                   |  7-0       |   0.656094
2 | ![Georgia](logos/georgia.png) |  Georgia                   |  7-0       |   0.639660
3 | ![Penn State](logos/penn-st.png) |  Penn State                |  6-0       |   0.635700
4 | ![Wisconsin](logos/wisconsin.png) |  Wisconsin                 |  6-0       |   0.633779
5 | ![TCU](logos/tcu.png) |  TCU                       |  6-0       |   0.623445
6 | ![USC](logos/southern-california.png) |  USC                       |  6-1       |   0.619119
7 | ![Clemson](logos/clemson.png) |  Clemson                   |  6-1       |   0.617413
8 | ![UCF](logos/ucf.png) |  UCF                       |  5-0       |   0.616993
9 | ![Ohio State](logos/ohio-st.png) |  Ohio State                |  6-1       |   0.613780
10 | ![South Florida](logos/south-fla.png) |  South Florida             |  6-0       |   0.606025
11 | ![Miami (FL)](logos/miami-fl.png) |  Miami (FL)                |  5-0       |   0.603985
12 | ![Michigan State](logos/michigan-st.png) |  Michigan State            |  5-1       |   0.601154
13 | ![North Carolina State](logos/north-carolina-st.png) |  North Carolina State      |  6-1       |   0.601148
14 | ![Michigan](logos/michigan.png) |  Michigan                  |  5-1       |   0.598193
15 | ![San Diego State](logos/san-diego-st.png) |  San Diego State           |  6-1       |   0.597598
16 | ![Notre Dame](logos/notre-dame.png) |  Notre Dame                |  5-1       |   0.597356
17 | ![Washington](logos/washington.png) |  Washington                |  6-1       |   0.594634
18 | ![Navy](logos/navy.png) |  Navy                      |  5-1       |   0.594476
19 | ![Washington State](logos/washington-st.png) |  Washington State          |  6-1       |   0.594250
20 | ![Oklahoma](logos/oklahoma.png) |  Oklahoma                  |  5-1       |   0.591778
21 | ![Oklahoma State](logos/oklahoma-st.png) |  Oklahoma State            |  5-1       |   0.590952
22 | ![Marshall](logos/marshall.png) |  Marshall                  |  5-1       |   0.586148
23 | ![Memphis](logos/memphis.png) |  Memphis                   |  5-1       |   0.582925
24 | ![Stanford](logos/stanford.png) |  Stanford                  |  5-2       |   0.581243
25 | ![Kentucky](logos/kentucky.png) |  Kentucky                  |  5-1       |   0.577906

[Full rankings](output/rankings.csv)

*Note*: These results do not include the Akron-W. Michigan game, yet to
be played on October 15, 2017.
