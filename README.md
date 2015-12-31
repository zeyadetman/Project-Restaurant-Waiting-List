a program that will implement a customer waiting list that
might be used by a restaurant using first come first serve
concept. The program should maintain the following
information for each group that is waiting:
 name
 group size
 in-restaurant status: whether the group has called ahead
or is waiting in the restaurant
The system does not take reservations for a specific time and
date (i.e. table of 4 for 7pm on Saturday), but it will allow for a
group to call ahead and get their name on the waiting list before
they arrive. Note: these call-ahead groups will still need to
check in when they arrive so the staff knows they are waiting in
the restaurant.
Groups are added to the wait list when they call-ahead or when
they arrive at the restaurant. The system will require that each
name used be unique. So when a group is added to the wait list,
the system must make sure that no other group is already using
that name.
When a table becomes available in the restaurant, the system
returns the name of the group that is in the restaurant and can sit
at that table (i.e. the number of seats at the table is greater than
or equal to the number of people in that group). Note that this
may not be the first (or even the second or third) group on the
wait list.
