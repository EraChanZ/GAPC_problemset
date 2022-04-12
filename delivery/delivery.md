### Drone Delivery

As a project, students from the technological university in Eindhoven
have been working on a drone delivery system. Since taking off is quite
costly the system consists of a drone and a ground delivery robot (GDR).
The drone will fly to a street where the GDR can then deliver packages
to the doors nearby before they fly to the next street.
Since time is of the essence it is crucial that this takes the least
amount of time possible.
To solve this problem the TU/e students need your help. They need you
to optimize the landing position of the drone to make sure that the
GDR can deliver the packages in the shortest amount of time.

The robot takes exactly one time step to go to the next house and back
and it can carry only one package at a time.

Given a street with houses find the optimal location for the drone to land.

#### Input:

The input consists of:
-One line with an integer n (2 <= n <= 10^6), the number of houses.
-One line with n integers, p1, p2, ..., pn, (0 <= pi <= 10^9), the number of
 packages to be delivered to each of the houses.


#### Output:

Output the landing location with the minimal delivery time.


Sample Input 1               Sample Output 1
|--------------------------|------------------------|
| 6                        | 3                      |
| 3 1 6 0 2 1              |                        |
|--------------------------|------------------------|

Sample Input 2               Sample Output 2
|--------------------------|------------------------|
| 7                        | 5*                     |
| 99 0 1 0 99 0 1          | 3 also possible        |
|--------------------------|------------------------|
