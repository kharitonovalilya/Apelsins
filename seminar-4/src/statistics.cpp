#include "statistics.h"
#include <cmath>
#include <algorithm>
#include <numeric>

std::map<std::string, double> calculate_statistics(const std::vector<double>& data) {
    std::map<std::string, double> stats;
    if (data.empty()) {
        return stats;
    }
    stats["count"] = data.size();
    
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    stats["sum"] = sum;
    
    double mean = sum / data.size();
    stats["mean"] = mean;
    
    double min_val = *std::min_element(data.begin(), data.end());
    stats["min"] = min_val;
    
    double max_val = *std::max_element(data.begin(), data.end());
    stats["max"] = max_val;
    
    stats["range"] = max_val - min_val;
    
    std::vector<double> sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());
    
    double median = 0;
    if (sorted_data.size() % 2 == 0) {
        median = (sorted_data[sorted_data.size()/2 - 1] + sorted_data[sorted_data.size()/2]) / 2.0;
    } else {
        median = sorted_data[sorted_data.size()/2];
    }
    stats["median"] = median;
    
    double variance = 0.0;
    for (double val : data) {
        variance += (val - mean) * (val - mean);
    }
    variance /= (data.size() - 1);
    stats["variance"] = variance;
    
    stats["std_deviation"] = std::sqrt(variance);
    
    if (sorted_data.size() < 4) {
        stats["q1"] = std::numeric_limits<double>::quiet_NaN();
        stats["q2"] = median;
        stats["q3"] = std::numeric_limits<double>::quiet_NaN();
        stats["iqr"] = std::numeric_limits<double>::quiet_NaN();
    } else {
        stats["q1"] = sorted_data[sorted_data.size() / 4];
        stats["q2"] = median;
        stats["q3"] = sorted_data[sorted_data.size() * 3 / 4];
        stats["iqr"] = stats["q3"] - stats["q1"];
    }
    return stats;
}