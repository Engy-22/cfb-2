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

After 10 weeks of play in the 2017-2018 season:

[Full rankings](output/rankings.csv)

 **Rank** |  |**Team**                  | **Record** | **Score**  
----------|--|---------------------------|------------|------------
1         | ![Alabama](logos/alabama.png) | Alabama                   |  9-0       |   0.632945
2         | ![Wisconsin](logos/wisconsin.png) | Wisconsin                 |  9-0       |   0.628933
3         | ![Georgia](logos/georgia.png) | Georgia                   |  9-0       |   0.623198
4         | ![Notre Dame](logos/notre-dame.png) | Notre Dame                |  8-1       |   0.610198
5         | ![UCF](logos/ucf.png) | UCF                       |  8-0       |   0.609453
6         | ![Miami (FL)](logos/miami-fl.png) | Miami (FL)                |  8-0       |   0.608820
7         | ![Clemson](logos/clemson.png) | Clemson                   |  8-1       |   0.607357
8         | ![Oklahoma](logos/oklahoma.png) | Oklahoma                  |  8-1       |   0.602627
9         | ![USC](logos/southern-california.png) | USC                       |  8-2       |   0.595639
10        | ![TCU](logos/tcu.png) | TCU                       |  8-1       |   0.594472
11        | ![Memphis](logos/memphis.png) | Memphis                   |  8-1       |   0.593387
12        | ![Washington](logos/washington.png) | Washington                |  8-1       |   0.591776
13        | ![Toledo](logos/toledo.png) | Toledo                    |  8-1       |   0.589080
14        | ![South Florida](logos/south-fla.png) | South Florida             |  8-1       |   0.584876
15        | ![Penn State](logos/penn-st.png) | Penn State                |  7-2       |   0.584232
16        | ![Michigan State](logos/michigan-st.png) | Michigan State            |  7-2       |   0.582822
17        | ![Ohio State](logos/ohio-st.png) | Ohio State                |  7-2       |   0.581993
18        | ![Boise State](logos/boise-st.png) | Boise State               |  7-2       |   0.578693
19        | ![Michigan](logos/michigan.png) | Michigan                  |  7-2       |   0.578616
20        | ![San Diego State](logos/san-diego-st.png) | San Diego State           |  8-2       |   0.577655
21        | ![Washington State](logos/washington-st.png) | Washington State          |  8-2       |   0.577503
22        | ![Oklahoma State](logos/oklahoma-st.png) | Oklahoma State            |  7-2       |   0.577309
23        | ![Mississippi State](logos/mississippi-st.png) | Mississippi State         |  7-2       |   0.568258
24        | ![Auburn](logos/auburn.png) | Auburn                    |  7-2       |   0.567051
25        | ![Virginia Tech](logos/virginia-tech.png) | Virginia Tech             |  7-2       |   0.565786
