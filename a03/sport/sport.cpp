#include "sport.hpp"
#include <utility>

namespace sport {

bool compare_pointers(const unsigned *a, const unsigned *b, const unsigned *time_a, const unsigned *time_b) {
    // Compare points first
    if (*a != *b) {
        return *a > *b; // Higher points are better
    }
    // Use time as a tiebreaker if points are equal
    return *time_a < *time_b; // Lower time is better
}

void sort(const unsigned **points_start, const unsigned **times_start, unsigned size) {
    // Implement a basic selection sort to avoid complex pointer swapping
    for (unsigned i = 0; i < size - 1; ++i) {
        unsigned min_index = i;
        for (unsigned j = i + 1; j < size; ++j) {
            // Use compare_pointers to find the best competitor
            if (!compare_pointers(points_start[min_index], points_start[j], times_start[min_index], times_start[j])) {
                min_index = j;
            }
        }
        // Swap pointers if needed
        if (min_index != i) {
            std::swap(points_start[i], points_start[min_index]);
            std::swap(times_start[i], times_start[min_index]);
        }
    }
}
} // namespace sport
