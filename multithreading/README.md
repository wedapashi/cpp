## Multithreading

Before we dwell into design and implementation-level aspects of multithreading, it is important to understand the WHY part of it.

First understand the following:

John Doe runs a bakery. When he wants to make a cake -- this is what happens.  
He gathers ingredients, and measures them in proportions, preps the equipment like pre-heating the oven, prepping the baking pans, etc.
He then, mixes the batter and pours into the pans. He then sets it all up for baking and waits as he bum a fag!
Once it is baked and cooled off, he whips the cream and then he decorates the cake with it. Done!

### Parallelism:

In a world of Parallelism, John Doe can in fact, do it faster with the help of Jane Doe.

While John is gathering ingredients, Jane Doe can measure the gathered ones into proportions.
Then John sets the oven for pre-heating while Jane Doe starts prepping the baking pans, because these two tasks can happen simultaneously. Then while it is being baked, John keeps an eye on it, while Jane is whipping the cream, and so on.

In a nutshell: 
>Multiple tasks literally executed at the same time. This is achieved by leveraging the multiple CPU Cores.


### Concurrency:

In a world of Concurrency, John Doe is alone, poor guy.

Nothing changes about he goes about gathering and measuring the ingredients, until he keeps things for baking. However, while it is being baked, he can whip the cream rather than just waits and smokes. 

In a nutshell,
>When we say concurrent, it does not always mean they run at the exact same instant. Instead, the system/scheduler manages/switches between several tasks.

---

### The `WHY` part

What is your end-goal?  
Why do you want your application to be a multithreaded application?  
What problem are you trying to solve?

Based on such design thought-provoking questions, you can choose your model for Concurrency.

All of these questions have *sane* answers that fall into the following 2 buckets:

1. Scalability
2. Separation of Concerns

---
### Scalability reason:

#### Amdahl's Law

```
                               1
Scalability Improvement = -----------
        Multiplier                 p
                          1 - p + ---
                                   n

Where: p: No. of tasks that you can do in parallel 
       n: No. of CPU cores                                   
```
#### Parallel Algorithms
Thankfully, Many standard library algorithms have parallel versions:

Example: `std::execution::par`

Suppose you have `std::vector` of `double`s.
And, you want to iterate over the whole vector and do something, such as may be apply a coefficient to them.

```
std::vector<double> readings;
// Assume readings have some data
const double gain { 1.031469 };
const double offset { -0.008364 };

std::for_each(std::execution::par,
             readings.begin(), readings.end(),
             [gain, offset](double& reading) {
                reading *= gain;
                reading += offset;
             })
```




