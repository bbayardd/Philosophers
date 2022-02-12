# Philosophers
The first task is related to multithreading, as a solution for the problem of dining philosophers.

There are some rules of this task:
N philosophers are sitting on a round table. Each have only one fork. There is a large bowl of spaghetti in the middle of the table. To eat all philosophers need to use a couple fork. Philosopher can eat, think or sleep. While they are eating, they are not thinking nor sleeping, while thinking, they are not eating nor sleeping -and, of course, while sleeping, they are not eating nor thinking. When they finish eating, they start sleeping, after sleeping they start thinking. 
Program take the following argument: 

num_of_philo(number of philosophers);

time_to_die(philosophers should start eating in time_to_die milliseconds since to last meal or they die);

time_to_eat(this time need to eating. During this time they can't die);

number_of_times_each_philosopher_must_eat(this is an optional argument, in its absence, philosophers should eat until no one dies);

Written in according with norminette.
