#pragma once
#ifndef LIST_HPP
#define LIST_HPP

class List {
 private:
  int m_count{};
  int *m_items{nullptr};

 public:
  List() = default;
  ~List();

  int Get(int index);
  void Insert(int index, int value);
  int Search(int val);
  void Remove(int index);
  int Count();
};

#endif  // LIST_HPP