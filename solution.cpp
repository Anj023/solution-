#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <stdexcept>


long long decode_value(const std::string& value, long long base) {
    return std::stoll(value, nullptr, base);
}


double lagrange_interpolation(const std::vector<std::pair<long long, long long>>& points) {
    int n = points.size();
    double constant_term = 0.0;
    
    for (int j = 0; j < n; ++j) {
        double lj = 1.0;
        long long xj = points[j].first;
        long long yj = points[j].second;
        
        for (int m = 0; m < n; ++m) {
            if (m != j) {
                long long xm = points[m].first;
                lj *= (0.0 - xm) / (xj - xm); 
            }
        }
        
        constant_term += yj * lj;
    }
    
    return constant_term;
}

int main() {
    
    std::vector<std::pair<long long, std::pair<long long, std::string>>> input = {
        {1, {10, "28735619723837"}},    
        {2, {16, "1A228867F0CA"}},   
        {3, {12, "32811A4AA0B7B"}},   
        {4, {11, "917978721331A"}},
        {5, {16, "1A22886782E1"}},   
        {6, {10, "28735619654702"}},
        {7, {14, "71AB5070CC4B"}},   
        {8, {9, "122662581541670"}},
        {9, {8, "642121030037605"}}
    };
    
    
    std::vector<std::pair<long long, long long>> points;
    for (const auto& entry : input) {
        long long x = entry.first;
        long long base = entry.second.first;
        std::string value = entry.second.second;
        long long y = decode_value(value, base);
        points.push_back({x, y});
    }
    
    
    double constant_term = lagrange_interpolation(points);
    
  
    std::cout << "Constant term (c): " << constant_term << std::endl;
    
    return 0;
}

