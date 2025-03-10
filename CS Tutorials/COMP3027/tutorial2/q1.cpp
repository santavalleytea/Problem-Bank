#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

struct Job
{
    int weight;
    int time;
};

bool compareJobs(const Job &a, const Job &b)
{
    return (static_cast<double>(a.weight) / a.time) > (static_cast<double>(b.weight) / b.time);
}

// Compute optimal schedule
std::pair<long long, std::vector<Job>> scheduleJobs(std::vector<Job> &jobs)
{
    // Sort jobs based on weight to time ratio in descending order
    std::sort(jobs.begin(), jobs.end(), compareJobs);

    long long completionTime = 0;
    long long totalWeightedCompletionTime = 0;

    for (std::size_t i = 0; i < jobs.size(); ++i)
    {
        completionTime += jobs[i].time;
        totalWeightedCompletionTime += static_cast<long long>(jobs[i].weight) * completionTime;
    }

    return std::pair<long long, std::vector<Job>>(totalWeightedCompletionTime, jobs);
}

// Test
int main()
{
    // {weight, processing_time}
    std::vector<Job> jobs;
    jobs.push_back({3, 5});
    jobs.push_back({1, 2});
    jobs.push_back({2, 1});
    jobs.push_back({4, 3});

    std::pair<long long, std::vector<Job>> result = scheduleJobs(jobs);
    long long optimalWeightedSum = result.first;
    std::vector<Job> sortedJobs = result.second;

    std::cout << "Optimal Weighted Sum of Completion Times: " << optimalWeightedSum << std::endl;
    std::cout << "Optimal Job Order (weight, time):" << std::endl;
    for (std::size_t i = 0; i < sortedJobs.size(); i++)
    {
        std::cout << "(" << sortedJobs[i].weight << ", " << sortedJobs[i].time << ") ";
    }
    std::cout << std::endl;

    return 0;
}
