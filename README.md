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

After 8 weeks of play in the 2017-2018 season:

[Full rankings](output/rankings.csv)

 **Rank** |  |**Team**                  | **Record** | **Score**  
----------|--|---------------------------|------------|------------
1         | ![Alabama](logos/alabama.png) | Alabama                   |  8-0       |   0.651301
2         | ![Penn State](logos/penn-st.png) | Penn State                |  7-0       |   0.635612
3         | ![Wisconsin](logos/wisconsin.png) | Wisconsin                 |  7-0       |   0.632975
4         | ![Georgia](logos/georgia.png) | Georgia                   |  7-0       |   0.623330
5         | ![TCU](logos/tcu.png) | TCU                       |  7-0       |   0.622111
6         | ![UCF](logos/ucf.png) | UCF                       |  6-0       |   0.620208
7         | ![South Florida](logos/south-fla.png) | South Florida             |  7-0       |   0.609341
8         | ![Miami (FL)](logos/miami-fl.png) | Miami (FL)                |  6-0       |   0.607455
9         | ![Clemson](logos/clemson.png) | Clemson                   |  6-1       |   0.603856
10        | ![Notre Dame](logos/notre-dame.png) | Notre Dame                |  6-1       |   0.603665
11        | ![Michigan State](logos/michigan-st.png) | Michigan State            |  6-1       |   0.603219
12        | ![Ohio State](logos/ohio-st.png) | Ohio State                |  6-1       |   0.600581
13        | ![Washington State](logos/washington-st.png) | Washington State          |  7-1       |   0.598082
14        | ![Oklahoma State](logos/oklahoma-st.png) | Oklahoma State            |  6-1       |   0.596902
15        | ![Oklahoma](logos/oklahoma.png) | Oklahoma                  |  6-1       |   0.596833
16        | ![Memphis](logos/memphis.png) | Memphis                   |  6-1       |   0.590409
17        | ![Marshall](logos/marshall.png) | Marshall                  |  6-1       |   0.589599
18        | ![North Carolina State](logos/north-carolina-st.png) | North Carolina State      |  6-1       |   0.588258
19        | ![USC](logos/southern-california.png) | USC                       |  6-2       |   0.587987
20        | ![Washington](logos/washington.png) | Washington                |  6-1       |   0.584834
21        | ![Virginia Tech](logos/virginia-tech.png) | Virginia Tech             |  6-1       |   0.581919
22        | ![Toledo](logos/toledo.png) | Toledo                    |  6-1       |   0.579632
23        | ![Michigan](logos/michigan.png) | Michigan                  |  5-2       |   0.570239
24        | ![Stanford](logos/stanford.png) | Stanford                  |  5-2       |   0.570150
25        | ![Boise State](logos/boise-st.png) | Boise State               |  5-2       |   0.570124
