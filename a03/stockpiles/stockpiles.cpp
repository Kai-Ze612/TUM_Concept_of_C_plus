#include "stockpiles.hpp"
#include <utility> // for std::swap

namespace stockpiles {

// Helper function to get parent index in heap
inline unsigned parent(unsigned i) { return (i - 1) / 2; }

// Helper function to get left child index in heap
inline unsigned left_child(unsigned i) { return 2 * i + 1; }

// Helper function to get right child index in heap
inline unsigned right_child(unsigned i) { return 2 * i + 2; }

// Helper function to maintain heap property
void heapify(Stockpile *stock_start, unsigned stock_len, unsigned i) {
    unsigned largest = i;
    unsigned left = left_child(i);
    unsigned right = right_child(i);

    // Compare with left child
    if (left < stock_len) {
        bool use_left = *(stock_start[left].bottles) > *(stock_start[largest].bottles) ||
            (*(stock_start[left].bottles) == *(stock_start[largest].bottles) &&
             stock_start[left].id < stock_start[largest].id);
        if (use_left) { largest = left; }
    }

    // Compare with right child
    if (right < stock_len) {
        bool use_right = *(stock_start[right].bottles) > *(stock_start[largest].bottles) ||
            (*(stock_start[right].bottles) == *(stock_start[largest].bottles) &&
             stock_start[right].id < stock_start[largest].id);
        if (use_right) { largest = right; }
    }

    // If largest is not root
    if (largest != i) {
        std::swap(stock_start[i], stock_start[largest]);
        heapify(stock_start, stock_len, largest);
    }
}

void init(Stockpile *stock_start, unsigned stock_len) {
    // Build max heap
    // Start from last non-leaf node and move up
    for (int i = stock_len / 2 - 1; i >= 0; i--) { heapify(stock_start, stock_len, i); }
}

bool serve(Stockpile *stock_start, unsigned stock_len, unsigned amount, Stockpile &which) {
    if (stock_len == 0 || *(stock_start[0].bottles) < amount) {
        return false; // Cannot serve the request
    }

    // Store the stockpile that will serve the request
    which = stock_start[0];

    // Update the number of bottles in the root stockpile
    *(stock_start[0].bottles) -= amount;

    // Maintain heap property
    heapify(stock_start, stock_len, 0);

    return true;
}

} // namespace stockpiles