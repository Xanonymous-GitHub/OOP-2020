#include "../src/queue.h"
#include <iostream>

TEST(QueueTestByNySelf, defaultConstructor) {
    Queue<int> q;
    ASSERT_EQ(0, q.size());
}

TEST(QueueTestByNySelf, push_int) {
    Queue<int> q;
    q.push(9487);
    q.push(66666);
    ASSERT_EQ(2, q.size());
    ASSERT_EQ(9487, q.at(0));
    ASSERT_EQ(66666, q.at(1));
}

TEST(QueueTestByNySelf, push_double) {
    Queue<double> q;
    q.push(2.718282);
    q.push(4444444.4444444);
    ASSERT_EQ(2, q.size());
    ASSERT_NEAR(2.718282, q.at(0), 0.0001);
    ASSERT_NEAR(4444444.4444444, q.at(1), 0.0001);
}

TEST(QueueTestByNySelf, push_char) {
    Queue<char> q;
    q.push('c');
    q.push('d');
    ASSERT_EQ(2, q.size());
    ASSERT_EQ('c', q.at(0));
    ASSERT_EQ('d', q.at(1));
}

TEST(QueueTestByNySelf, pop_int) {
    Queue<int> q;
    q.push(949494);
    q.push(878787);
    ASSERT_EQ(949494, q.pop());
    ASSERT_EQ(1, q.size());
    ASSERT_EQ(878787, q.pop());
    ASSERT_EQ(0, q.size());
}

TEST(QueueTestByNySelf, pop_double) {
    Queue<double> q;
    q.push(1.4142135);
    q.push(66666.666666);
    ASSERT_NEAR(1.4142135, q.pop(), 0.0001);
    ASSERT_EQ(1, q.size());
    ASSERT_NEAR(66666.666666, q.pop(), 0.0001);
    ASSERT_EQ(0, q.size());
}

TEST(QueueTestByNySelf, pop_char) {
    Queue<char> q;
    q.push('a');
    q.push('x');
    ASSERT_EQ('a', q.pop());
    ASSERT_EQ(1, q.size());
    ASSERT_EQ('x', q.pop());
    ASSERT_EQ(0, q.size());
}

TEST(QueueTestByNySelf, pop_empty_exception) {
    Queue<std::string> q;
    ASSERT_THROW(q.pop(), std::string);
}

TEST(QueueTestByNySelf, push_10000_long_long_and_pop_them) {
    Queue<long long> q;
    for (int i = 0; i < 10000; i++) {
        q.push(i);
        ASSERT_EQ(i + 1, q.size());
    }
    for (int i = 0; i < 10000; i++) {
        ASSERT_EQ(i, q.pop());
        ASSERT_EQ(9999 - i, q.size());
    }
}

TEST(QueueTestByNySelf, at_out_of_range_exception) {
    Queue<int> q;
    q.push(9);
    q.push(4);
    q.push(8);
    q.push(7);
    ASSERT_THROW(q.at(-99999), std::string);
    ASSERT_THROW(q.at(272727277272), std::string);
}

TEST(QueueTestByNySelf, clear) {
    Queue<int> q;
    q.push(9);
    q.push(4);
    q.push(8);
    q.push(7);
    ASSERT_EQ(4, q.size());
    q.clear();
    ASSERT_EQ(0, q.size());
}