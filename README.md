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

After 9 weeks of play in the 2017-2018 season:

[Full rankings](output/rankings.csv)

 **Rank** |  |**Team**                  | **Record** | **Score**  
----------|--|---------------------------|------------|------------
1         | ![Alabama](logos/alabama.png) | Alabama                   |  8-0       |   0.633952
2         | ![Wisconsin](logos/wisconsin.png) | Wisconsin                 |  8-0       |   0.632831
3         | ![Georgia](logos/georgia.png) | Georgia                   |  8-0       |   0.624341
4         | ![Notre Dame](logos/notre-dame.png) | Notre Dame                |  7-1       |   0.609672
5         | ![Penn State](logos/penn-st.png) | Penn State                |  7-1       |   0.609238
6         | ![UCF](logos/ucf.png) | UCF                       |  7-0       |   0.609075
7         | ![Ohio State](logos/ohio-st.png) | Ohio State                |  7-1       |   0.608394
8         | ![Clemson](logos/clemson.png) | Clemson                   |  7-1       |   0.608058
9         | ![Miami (FL)](logos/miami-fl.png) | Miami (FL)                |  7-0       |   0.606711
10        | ![Oklahoma](logos/oklahoma.png) | Oklahoma                  |  7-1       |   0.601807
11        | ![Oklahoma State](logos/oklahoma-st.png) | Oklahoma State            |  7-1       |   0.601107
12        | ![TCU](logos/tcu.png) | TCU                       |  7-1       |   0.594063
13        | ![Memphis](logos/memphis.png) | Memphis                   |  7-1       |   0.593829
14        | ![USC](logos/southern-california.png) | USC                       |  7-2       |   0.593425
15        | ![Washington](logos/washington.png) | Washington                |  7-1       |   0.589408
16        | ![Virginia Tech](logos/virginia-tech.png) | Virginia Tech             |  7-1       |   0.587807
17        | ![Toledo](logos/toledo.png) | Toledo                    |  7-1       |   0.585008
18        | ![South Florida](logos/south-fla.png) | South Florida             |  7-1       |   0.583016
19        | ![Michigan State](logos/michigan-st.png) | Michigan State            |  6-2       |   0.578419
20        | ![Boise State](logos/boise-st.png) | Boise State               |  6-2       |   0.577765
21        | ![San Diego State](logos/san-diego-st.png) | San Diego State           |  7-2       |   0.576956
22        | ![Michigan](logos/michigan.png) | Michigan                  |  6-2       |   0.575891
23        | ![Stanford](logos/stanford.png) | Stanford                  |  6-2       |   0.575565
24        | ![Washington State](logos/washington-st.png) | Washington State          |  7-2       |   0.573687
25        | ![South Carolina](logos/south-carolina.png) | South Carolina            |  6-2       |   0.573186
