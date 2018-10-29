Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls   s/call   s/call  name    
 31.19      2.47     2.47 12472402     0.00     0.00  swap_chains_step(Assignment const*, Solution const&, std::vector<int, std::allocator<int> >)
 19.07      3.98     1.51  6125177     0.00     0.00  get_next_edge_weighted(GreedyManager*)
 16.42      5.28     1.30  6123297     0.00     0.00  get_next_edge_random(GreedyManager*)
  9.85      6.06     0.78 14197701     0.00     0.00  SuitableEdgesIterator::get_next_suitable_edge(std::vector<bool, std::allocator<bool> > const&)
  3.98      6.38     0.32 36055299     0.00     0.00  std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>::operator()()
  2.15      6.55     0.17  6635015     0.00     0.00  RandomGenerator::get_rand_int64()
  1.70      6.68     0.14  6083352     0.00     0.00  get_random_edge_weighted(GreedyManager*, std::vector<Edge const*, std::allocator<Edge const*> > const&)
  1.52      6.80     0.12    85657     0.00     0.00  get_greedy_path(GreedyManager*)
  1.39      6.91     0.11 16884401     0.00     0.00  void std::vector<Airport*, std::allocator<Airport*> >::_M_realloc_insert<Airport* const&>(__gnu_cxx::__normal_iterator<Airport**, std::vector<Airport*, std::allocator<Airport*> > >, Airport* const&)
  1.39      7.02     0.11      751     0.00     0.00  apply_all_swaps_2v(Assignment*, Solution)
  1.33      7.13     0.11  8387713     0.00     0.00  swap_chains(Assignment*, Solution, std::vector<int, std::allocator<int> >)
  1.01      7.21     0.08 16884401     0.00     0.00  void std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > >::emplace_back<std::pair<Edge const*, Edge const*> >(std::pair<Edge const*, Edge const*>&&)
  1.01      7.29     0.08   123903     0.00     0.00  get_least_visited_edge(GreedyManager*)
  0.88      7.36     0.07 25335595     0.00     0.00  fixed_zone_order_dp(Assignment const*)
  0.88      7.43     0.07  8387713     0.00     0.00  std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > >::_M_fill_insert(__gnu_cxx::__normal_iterator<std::pair<Edge const*, Edge const*>*, std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > > >, unsigned long, std::pair<Edge const*, Edge const*> const&)
  0.76      7.49     0.06  9145333     0.00     0.00  void std::vector<Edge const*, std::allocator<Edge const*> >::emplace_back<Edge const*>(Edge const*&&)
  0.63      7.54     0.05  3404257     0.00     0.00  std::__detail::_Map_base<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true>, true>::operator[](std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
  0.63      7.59     0.05      751     0.00     0.00  void std::shuffle<__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&>(__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, __gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&)
  0.51      7.63     0.04        1     0.04     0.12  Assignment::read_data()
  0.38      7.66     0.03  8169378     0.00     0.00  void std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::emplace_back<std::vector<int, std::allocator<int> > >(std::vector<int, std::allocator<int> >&&)
  0.38      7.69     0.03  6301897     0.00     0.00  std::discrete_distribution<int>::param_type::_M_initialize()
  0.25      7.71     0.02  1702028     0.00     0.00  void std::vector<Edge*, std::allocator<Edge*> >::emplace_back<Edge*>(Edge*&&)
  0.25      7.73     0.02   219086     0.00     0.00  Assignment::init_can_from_to()
  0.25      7.75     0.02   184620     0.00     0.00  Edge const** std::__move_merge<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, Edge const**, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  0.25      7.77     0.02   124620     0.00     0.00  __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > > std::__move_merge<Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  0.25      7.79     0.02       33     0.00     0.00  solve_simple(Assignment*)
  0.25      7.81     0.02       22     0.00     0.00  void std::vector<Edge, std::allocator<Edge> >::_M_realloc_insert<Edge>(__gnu_cxx::__normal_iterator<Edge*, std::vector<Edge, std::allocator<Edge> > >, Edge&&)
  0.19      7.82     0.02                             LocalManager::local_step(std::vector<int, std::allocator<int> >)
  0.13      7.83     0.01  3404457     0.00     0.00  std::_Hashtable<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true> >::_M_find_before_node(unsigned long, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, unsigned long) const
  0.13      7.84     0.01   545645     0.00     0.00  std::pair<std::_Rb_tree_iterator<int>, bool> std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_insert_unique<int const&>(int const&)
  0.13      7.85     0.01   277620     0.00     0.00  void std::__insertion_sort<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  0.13      7.86     0.01   219086     0.00     0.00  LocalOptimizeManager::apply_random_optimization(Assignment*, Solution)
  0.13      7.87     0.01   218335     0.00     0.00  generate_k(int, int)
  0.13      7.88     0.01   218335     0.00     0.00  std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_erase(std::_Rb_tree_node<int>*)
  0.13      7.89     0.01      751     0.00     0.00  std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::~vector()
  0.13      7.90     0.01        1     0.01     0.01  std::vector<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >, std::allocator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > > >::_M_fill_insert(__gnu_cxx::__normal_iterator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >*, std::vector<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >, std::allocator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > > > >, unsigned long, std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > const&)
  0.13      7.91     0.01                             dp_construct_solution_from(Assignment const*, std::vector<std::vector<Edge const*, std::allocator<Edge const*> >, std::allocator<std::vector<Edge const*, std::allocator<Edge const*> > > >, int)
  0.06      7.92     0.01                             swap_anyway(Assignment const*, int, int)
  0.06      7.92     0.01                             read_and_solve(std::function<Solution (Assignment*)>)
  0.00      7.92     0.00   770857     0.00     0.00  void std::vector<Edge const*, std::allocator<Edge const*> >::_M_realloc_insert<Edge const* const&>(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const* const&)
  0.00      7.92     0.00   545645     0.00     0.00  void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&)
  0.00      7.92     0.00   438181     0.00     0.00  std::_Function_base::_Base_manager<Solution (*)(Assignment*, Solution)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation)
  0.00      7.92     0.00   438172     0.00     0.00  std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&)
  0.00      7.92     0.00   219090     0.00     0.00  std::function<Solution (Assignment*, Solution)>::function(std::function<Solution (Assignment*, Solution)> const&)
  0.00      7.92     0.00   109360     0.00     0.00  swap_chains_2v(Assignment*, Solution)
  0.00      7.92     0.00   108975     0.00     0.00  swap_chains_3v(Assignment*, Solution)
  0.00      7.92     0.00    85657     0.00     0.00  greedy(Assignment const*)
  0.00      7.92     0.00    85657     0.00     0.00  std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment const*)>::_M_invoke(std::_Any_data const&, Assignment*&&)
  0.00      7.92     0.00    85657     0.00     0.00  std::vector<bool, std::allocator<bool> >::_M_fill_insert(std::_Bit_iterator, unsigned long, bool)
  0.00      7.92     0.00    78975     0.00     0.00  Solution::score()
  0.00      7.92     0.00    60000     0.00     0.00  void std::__merge_sort_with_buffer<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  0.00      7.92     0.00    30000     0.00     0.00  void std::__merge_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, long, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, long, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  0.00      7.92     0.00    30000     0.00     0.00  void std::__stable_sort_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  0.00      7.92     0.00      751     0.00     0.00  std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::reserve(unsigned long)
  0.00      7.92     0.00      401     0.00     0.00  void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char*>(char*, char*, std::forward_iterator_tag)
  0.00      7.92     0.00      201     0.00     0.00  std::_Hashtable<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true> >::_M_insert_unique_node(unsigned long, unsigned long, std::__detail::_Hash_node<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, true>*, unsigned long)
  0.00      7.92     0.00      200     0.00     0.00  std::vector<std::vector<Edge const*, std::allocator<Edge const*> >, std::allocator<std::vector<Edge const*, std::allocator<Edge const*> > > >::_M_default_append(unsigned long)
  0.00      7.92     0.00      200     0.00     0.00  void std::__inplace_stable_sort<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  0.00      7.92     0.00      197     0.00     0.00  void std::vector<Airport*, std::allocator<Airport*> >::_M_realloc_insert<Airport*>(__gnu_cxx::__normal_iterator<Airport**, std::vector<Airport*, std::allocator<Airport*> > >, Airport*&&)
  0.00      7.92     0.00       33     0.00     0.00  std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment*)>::_M_invoke(std::_Any_data const&, Assignment*&&)
  0.00      7.92     0.00        9     0.00     0.00  void std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_realloc_insert<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&>(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
  0.00      7.92     0.00        9     0.00     0.00  void std::vector<std::vector<Airport*, std::allocator<Airport*> >, std::allocator<std::vector<Airport*, std::allocator<Airport*> > > >::_M_realloc_insert<std::vector<Airport*, std::allocator<Airport*> > >(__gnu_cxx::__normal_iterator<std::vector<Airport*, std::allocator<Airport*> >*, std::vector<std::vector<Airport*, std::allocator<Airport*> >, std::allocator<std::vector<Airport*, std::allocator<Airport*> > > > >, std::vector<Airport*, std::allocator<Airport*> >&&)
  0.00      7.92     0.00        7     0.00     0.00  std::_Function_base::_Base_manager<Solution (*)(Assignment const*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation)
  0.00      7.92     0.00        3     0.00     0.00  get_max_edges_cnt(Assignment const*)
  0.00      7.92     0.00        3     0.00     0.00  std::vector<Edge const*, std::allocator<Edge const*> >::operator=(std::vector<Edge const*, std::allocator<Edge const*> > const&)
  0.00      7.92     0.00        3     0.00     0.00  std::function<Solution (Assignment*)>::function(std::function<Solution (Assignment*)> const&)
  0.00      7.92     0.00        2     0.00     0.00  std::_Function_base::_Base_manager<main::{lambda(Assignment*)#1}>::_M_manager(std::_Any_data&, std::_Function_base::_Base_manager<main::{lambda(Assignment*)#1}> const&, std::_Manager_operation)
  0.00      7.92     0.00        1     0.00     0.00  _GLOBAL__sub_I__Z14get_time_in_msNSt6chrono10time_pointINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEEE
  0.00      7.92     0.00        1     0.00     0.04  get_max_edges_index_bs(std::function<Solution (Assignment*)>, Assignment*)
  0.00      7.92     0.00        1     0.00     0.32  get_max_edges_index_ls(std::function<Solution (Assignment*)>, Assignment*, int, int)
  0.00      7.92     0.00        1     0.00     7.31  run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*)
  0.00      7.92     0.00        1     0.00     7.66  calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*)
  0.00      7.92     0.00        1     0.00     0.02  run_main(std::function<Solution (Assignment*)>, Assignment*, bool, int)
  0.00      7.92     0.00        1     0.00     0.00  std::_Function_base::_Base_manager<Solution (*)(Assignment*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation)
  0.00      7.92     0.00        1     0.00     7.69  std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&)
  0.00      7.92     0.00        1     0.00     0.00  std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_default_append(unsigned long)

 %         the percentage of the total running time of the
time       program used by this function.

cumulative a running sum of the number of seconds accounted
 seconds   for by this function and those listed above it.

 self      the number of seconds accounted for by this
seconds    function alone.  This is the major sort for this
           listing.

calls      the number of times this function was invoked, if
           this function is profiled, else blank.

 self      the average number of milliseconds spent in this
ms/call    function per call, if this function is profiled,
	   else blank.

 total     the average number of milliseconds spent in this
ms/call    function and its descendents per call, if this
	   function is profiled, else blank.

name       the name of the function.  This is the minor sort
           for this listing. The index shows the location of
	   the function in the gprof listing. If the index is
	   in parenthesis it shows where it would appear in
	   the gprof listing if it were to be printed.

Copyright (C) 2012-2018 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

		     Call graph (explanation follows)


granularity: each sample hit covers 2 byte(s) for 0.13% of 7.92 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     99.6    0.01    7.89                 read_and_solve(std::function<Solution (Assignment*)>) [1]
                0.00    7.69       1/1           std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&) [2]
                0.04    0.08       1/1           Assignment::read_data() [22]
                0.00    0.05   30000/30000       void std::__stable_sort_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [30]
                0.02    0.00 1702028/1702028     void std::vector<Edge*, std::allocator<Edge*> >::emplace_back<Edge*>(Edge*&&) [42]
                0.01    0.00 1702028/9145333     void std::vector<Edge const*, std::allocator<Edge const*> >::emplace_back<Edge const*>(Edge const*&&) [27]
                0.00    0.00     200/277620      void std::__insertion_sort<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [49]
                0.00    0.00     200/200         std::vector<std::vector<Edge const*, std::allocator<Edge const*> >, std::allocator<std::vector<Edge const*, std::allocator<Edge const*> > > >::_M_default_append(unsigned long) [72]
                0.00    0.00     200/200         void std::__inplace_stable_sort<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [73]
                0.00    0.00       1/78975       Solution::score() [67]
-----------------------------------------------
                0.00    7.69       1/1           read_and_solve(std::function<Solution (Assignment*)>) [1]
[2]     97.0    0.00    7.69       1         std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&) [2]
                0.00    7.66       1/1           calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
                0.00    0.02       1/1           run_main(std::function<Solution (Assignment*)>, Assignment*, bool, int) [41]
                0.00    0.00       1/1           std::_Function_base::_Base_manager<Solution (*)(Assignment*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [83]
                0.00    0.00       1/78975       Solution::score() [67]
                0.00    0.00       1/7           std::_Function_base::_Base_manager<Solution (*)(Assignment const*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [77]
                0.00    0.00       1/438181      std::_Function_base::_Base_manager<Solution (*)(Assignment*, Solution)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [64]
-----------------------------------------------
                0.00    7.66       1/1           std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&) [2]
[3]     96.8    0.00    7.66       1         calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
                0.00    7.31       1/1           run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [4]
                0.00    0.32       1/1           get_max_edges_index_ls(std::function<Solution (Assignment*)>, Assignment*, int, int) [17]
                0.00    0.04       1/1           get_max_edges_index_bs(std::function<Solution (Assignment*)>, Assignment*) [35]
                0.00    0.00       3/3           std::function<Solution (Assignment*)>::function(std::function<Solution (Assignment*)> const&) [80]
                0.00    0.00       3/7           std::_Function_base::_Base_manager<Solution (*)(Assignment const*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [77]
                0.00    0.00       2/3           get_max_edges_cnt(Assignment const*) [78]
                0.00    0.00       1/219090      std::function<Solution (Assignment*, Solution)>::function(std::function<Solution (Assignment*, Solution)> const&) [65]
                0.00    0.00       1/438181      std::_Function_base::_Base_manager<Solution (*)(Assignment*, Solution)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [64]
-----------------------------------------------
                0.00    7.31       1/1           calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
[4]     92.3    0.00    7.31       1         run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [4]
                0.00    4.15   78905/85657       std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment const*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [7]
                0.01    3.15  219086/219086      std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&) <cycle 1> [9]
                0.00    0.00       2/6635015     RandomGenerator::get_rand_int64() [20]
                0.00    0.00   78905/78975       Solution::score() [67]
                0.00    0.00       3/3           std::vector<Edge const*, std::allocator<Edge const*> >::operator=(std::vector<Edge const*, std::allocator<Edge const*> > const&) [79]
                0.00    0.00       2/2           std::_Function_base::_Base_manager<main::{lambda(Assignment*)#1}>::_M_manager(std::_Any_data&, std::_Function_base::_Base_manager<main::{lambda(Assignment*)#1}> const&, std::_Manager_operation) [81]
-----------------------------------------------
                0.12    4.38   85657/85657       greedy(Assignment const*) [6]
[5]     56.8    0.12    4.38   85657         get_greedy_path(GreedyManager*) [5]
                1.51    0.63 6125177/6125177     get_next_edge_weighted(GreedyManager*) [12]
                1.30    0.58 6123297/6123297     get_next_edge_random(GreedyManager*) [14]
                0.07    0.22 24620851/25335595     fixed_zone_order_dp(Assignment const*) [19]
                0.08    0.00  123903/123903      get_least_visited_edge(GreedyManager*) [25]
                0.00    0.00  770857/770857      void std::vector<Edge const*, std::allocator<Edge const*> >::_M_realloc_insert<Edge const* const&>(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const* const&) [62]
-----------------------------------------------
                0.00    4.50   85657/85657       std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment const*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [7]
[6]     56.8    0.00    4.50   85657         greedy(Assignment const*) [6]
                0.12    4.38   85657/85657       get_greedy_path(GreedyManager*) [5]
                0.00    0.00   85657/85657       std::vector<bool, std::allocator<bool> >::_M_fill_insert(std::_Bit_iterator, unsigned long, bool) [66]
-----------------------------------------------
                0.00    0.04     680/85657       get_max_edges_index_bs(std::function<Solution (Assignment*)>, Assignment*) [35]
                0.00    0.32    6072/85657       get_max_edges_index_ls(std::function<Solution (Assignment*)>, Assignment*, int, int) [17]
                0.00    4.15   78905/85657       run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [4]
[7]     56.8    0.00    4.50   85657         std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment const*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [7]
                0.00    4.50   85657/85657       greedy(Assignment const*) [6]
-----------------------------------------------
[8]     40.0    0.01    3.15  219086+438172  <cycle 1 as a whole> [8]
                0.00    3.12  438172             std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&) <cycle 1> [9]
                0.01    0.03  219086             LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) <cycle 1> [33]
-----------------------------------------------
                              219086             LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) <cycle 1> [33]
                0.01    3.15  219086/219086      run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [4]
[9]     39.4    0.00    3.12  438172         std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&) <cycle 1> [9]
                0.11    2.91     751/751         apply_all_swaps_2v(Assignment*, Solution) [10]
                0.00    0.05  109360/109360      swap_chains_2v(Assignment*, Solution) [29]
                0.00    0.05  108975/108975      swap_chains_3v(Assignment*, Solution) [31]
                              219086             LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) <cycle 1> [33]
-----------------------------------------------
                0.11    2.91     751/751         std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&) <cycle 1> [9]
[10]    38.1    0.11    2.91     751         apply_all_swaps_2v(Assignment*, Solution) [10]
                0.10    1.81 8169378/8387713     swap_chains(Assignment*, Solution, std::vector<int, std::allocator<int> >) [13]
                0.05    0.91     751/751         void std::shuffle<__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&>(__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, __gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&) [15]
                0.03    0.00 8169378/8169378     void std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::emplace_back<std::vector<int, std::allocator<int> > >(std::vector<int, std::allocator<int> >&&) [36]
                0.01    0.00     751/751         std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::~vector() [51]
                0.00    0.00     751/751         std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::reserve(unsigned long) [69]
-----------------------------------------------
                0.81    0.10 4084689/12472402     void std::shuffle<__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&>(__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, __gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&) [15]
                1.66    0.20 8387713/12472402     swap_chains(Assignment*, Solution, std::vector<int, std::allocator<int> >) [13]
[11]    34.9    2.47    0.30 12472402         swap_chains_step(Assignment const*, Solution const&, std::vector<int, std::allocator<int> >) [11]
                0.11    0.00 16884401/16884401     void std::vector<Airport*, std::allocator<Airport*> >::_M_realloc_insert<Airport* const&>(__gnu_cxx::__normal_iterator<Airport**, std::vector<Airport*, std::allocator<Airport*> > >, Airport* const&) [23]
                0.08    0.00 16884401/16884401     void std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > >::emplace_back<std::pair<Edge const*, Edge const*> >(std::pair<Edge const*, Edge const*>&&) [24]
                0.07    0.00 8387713/8387713     std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > >::_M_fill_insert(__gnu_cxx::__normal_iterator<std::pair<Edge const*, Edge const*>*, std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > > >, unsigned long, std::pair<Edge const*, Edge const*> const&) [26]
                0.04    0.00 4084689/36055299     std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>::operator()() [18]
-----------------------------------------------
                1.51    0.63 6125177/6125177     get_greedy_path(GreedyManager*) [5]
[12]    27.0    1.51    0.63 6125177         get_next_edge_weighted(GreedyManager*) [12]
                0.41    0.00 7438426/14197701     SuitableEdgesIterator::get_next_suitable_edge(std::vector<bool, std::allocator<bool> > const&) [16]
                0.14    0.03 6083352/6083352     get_random_edge_weighted(GreedyManager*, std::vector<Edge const*, std::allocator<Edge const*> > const&) [21]
                0.05    0.00 7438426/9145333     void std::vector<Edge const*, std::allocator<Edge const*> >::emplace_back<Edge const*>(Edge const*&&) [27]
-----------------------------------------------
                0.00    0.02  108975/8387713     swap_chains_3v(Assignment*, Solution) [31]
                0.00    0.02  109360/8387713     swap_chains_2v(Assignment*, Solution) [29]
                0.10    1.81 8169378/8387713     apply_all_swaps_2v(Assignment*, Solution) [10]
[13]    24.8    0.11    1.86 8387713         swap_chains(Assignment*, Solution, std::vector<int, std::allocator<int> >) [13]
                1.66    0.20 8387713/12472402     swap_chains_step(Assignment const*, Solution const&, std::vector<int, std::allocator<int> >) [11]
                0.00    0.00  101496/25335595     fixed_zone_order_dp(Assignment const*) [19]
-----------------------------------------------
                1.30    0.58 6123297/6123297     get_greedy_path(GreedyManager*) [5]
[14]    23.7    1.30    0.58 6123297         get_next_edge_random(GreedyManager*) [14]
                0.37    0.00 6759275/14197701     SuitableEdgesIterator::get_next_suitable_edge(std::vector<bool, std::allocator<bool> > const&) [16]
                0.16    0.05 6081429/6635015     RandomGenerator::get_rand_int64() [20]
-----------------------------------------------
                0.05    0.91     751/751         apply_all_swaps_2v(Assignment*, Solution) [10]
[15]    12.1    0.05    0.91     751         void std::shuffle<__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&>(__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, __gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&) [15]
                0.81    0.10 4084689/12472402     swap_chains_step(Assignment const*, Solution const&, std::vector<int, std::allocator<int> >) [11]
-----------------------------------------------
                0.37    0.00 6759275/14197701     get_next_edge_random(GreedyManager*) [14]
                0.41    0.00 7438426/14197701     get_next_edge_weighted(GreedyManager*) [12]
[16]     9.8    0.78    0.00 14197701         SuitableEdgesIterator::get_next_suitable_edge(std::vector<bool, std::allocator<bool> > const&) [16]
-----------------------------------------------
                0.00    0.32       1/1           calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
[17]     4.0    0.00    0.32       1         get_max_edges_index_ls(std::function<Solution (Assignment*)>, Assignment*, int, int) [17]
                0.00    0.32    6072/85657       std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment const*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [7]
                0.00    0.00       1/78975       Solution::score() [67]
-----------------------------------------------
                0.04    0.00 4084689/36055299     swap_chains_step(Assignment const*, Solution const&, std::vector<int, std::allocator<int> >) [11]
                0.06    0.00 6635015/36055299     RandomGenerator::get_rand_int64() [20]
                0.22    0.00 25335595/36055299     fixed_zone_order_dp(Assignment const*) [19]
[18]     4.0    0.32    0.00 36055299         std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>::operator()() [18]
-----------------------------------------------
                              714744             fixed_zone_order_dp(Assignment const*) [19]
                0.00    0.00  101496/25335595     swap_chains(Assignment*, Solution, std::vector<int, std::allocator<int> >) [13]
                0.00    0.00  219086/25335595     LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) <cycle 1> [33]
                0.00    0.00  394162/25335595     get_random_edge_weighted(GreedyManager*, std::vector<Edge const*, std::allocator<Edge const*> > const&) [21]
                0.07    0.22 24620851/25335595     get_greedy_path(GreedyManager*) [5]
[19]     3.7    0.07    0.22 25335595+714744  fixed_zone_order_dp(Assignment const*) [19]
                0.22    0.00 25335595/36055299     std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>::operator()() [18]
                              714744             fixed_zone_order_dp(Assignment const*) [19]
-----------------------------------------------
                0.00    0.00       2/6635015     run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [4]
                0.00    0.00    4950/6635015     solve_simple(Assignment*) [39]
                0.01    0.00  548634/6635015     generate_k(int, int) [32]
                0.16    0.05 6081429/6635015     get_next_edge_random(GreedyManager*) [14]
[20]     2.9    0.17    0.06 6635015         RandomGenerator::get_rand_int64() [20]
                0.06    0.00 6635015/36055299     std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>::operator()() [18]
-----------------------------------------------
                0.14    0.03 6083352/6083352     get_next_edge_weighted(GreedyManager*) [12]
[21]     2.1    0.14    0.03 6083352         get_random_edge_weighted(GreedyManager*, std::vector<Edge const*, std::allocator<Edge const*> > const&) [21]
                0.03    0.00 6082811/6301897     std::discrete_distribution<int>::param_type::_M_initialize() [37]
                0.00    0.00  394162/25335595     fixed_zone_order_dp(Assignment const*) [19]
-----------------------------------------------
                0.04    0.08       1/1           read_and_solve(std::function<Solution (Assignment*)>) [1]
[22]     1.5    0.04    0.08       1         Assignment::read_data() [22]
                0.05    0.01 3404257/3404257     std::__detail::_Map_base<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true>, true>::operator[](std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [28]
                0.02    0.00      22/22          void std::vector<Edge, std::allocator<Edge> >::_M_realloc_insert<Edge>(__gnu_cxx::__normal_iterator<Edge*, std::vector<Edge, std::allocator<Edge> > >, Edge&&) [45]
                0.00    0.00     200/3404457     std::_Hashtable<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true> >::_M_find_before_node(unsigned long, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, unsigned long) const [47]
                0.00    0.00     197/197         void std::vector<Airport*, std::allocator<Airport*> >::_M_realloc_insert<Airport*>(__gnu_cxx::__normal_iterator<Airport**, std::vector<Airport*, std::allocator<Airport*> > >, Airport*&&) [74]
                0.00    0.00     191/401         void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char*>(char*, char*, std::forward_iterator_tag) [70]
                0.00    0.00       9/9           void std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_realloc_insert<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&>(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [75]
                0.00    0.00       9/9           void std::vector<std::vector<Airport*, std::allocator<Airport*> >, std::allocator<std::vector<Airport*, std::allocator<Airport*> > > >::_M_realloc_insert<std::vector<Airport*, std::allocator<Airport*> > >(__gnu_cxx::__normal_iterator<std::vector<Airport*, std::allocator<Airport*> >*, std::vector<std::vector<Airport*, std::allocator<Airport*> >, std::allocator<std::vector<Airport*, std::allocator<Airport*> > > > >, std::vector<Airport*, std::allocator<Airport*> >&&) [76]
                0.00    0.00       1/1           std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_default_append(unsigned long) [84]
-----------------------------------------------
                0.11    0.00 16884401/16884401     swap_chains_step(Assignment const*, Solution const&, std::vector<int, std::allocator<int> >) [11]
[23]     1.4    0.11    0.00 16884401         void std::vector<Airport*, std::allocator<Airport*> >::_M_realloc_insert<Airport* const&>(__gnu_cxx::__normal_iterator<Airport**, std::vector<Airport*, std::allocator<Airport*> > >, Airport* const&) [23]
-----------------------------------------------
                0.08    0.00 16884401/16884401     swap_chains_step(Assignment const*, Solution const&, std::vector<int, std::allocator<int> >) [11]
[24]     1.0    0.08    0.00 16884401         void std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > >::emplace_back<std::pair<Edge const*, Edge const*> >(std::pair<Edge const*, Edge const*>&&) [24]
-----------------------------------------------
                0.08    0.00  123903/123903      get_greedy_path(GreedyManager*) [5]
[25]     1.0    0.08    0.00  123903         get_least_visited_edge(GreedyManager*) [25]
-----------------------------------------------
                0.07    0.00 8387713/8387713     swap_chains_step(Assignment const*, Solution const&, std::vector<int, std::allocator<int> >) [11]
[26]     0.9    0.07    0.00 8387713         std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > >::_M_fill_insert(__gnu_cxx::__normal_iterator<std::pair<Edge const*, Edge const*>*, std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > > >, unsigned long, std::pair<Edge const*, Edge const*> const&) [26]
-----------------------------------------------
                0.00    0.00    4879/9145333     solve_simple(Assignment*) [39]
                0.01    0.00 1702028/9145333     read_and_solve(std::function<Solution (Assignment*)>) [1]
                0.05    0.00 7438426/9145333     get_next_edge_weighted(GreedyManager*) [12]
[27]     0.8    0.06    0.00 9145333         void std::vector<Edge const*, std::allocator<Edge const*> >::emplace_back<Edge const*>(Edge const*&&) [27]
-----------------------------------------------
                0.05    0.01 3404257/3404257     Assignment::read_data() [22]
[28]     0.8    0.05    0.01 3404257         std::__detail::_Map_base<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true>, true>::operator[](std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [28]
                0.01    0.00 3404257/3404457     std::_Hashtable<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true> >::_M_find_before_node(unsigned long, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, unsigned long) const [47]
                0.00    0.00     201/401         void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char*>(char*, char*, std::forward_iterator_tag) [70]
                0.00    0.00     201/201         std::_Hashtable<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true> >::_M_insert_unique_node(unsigned long, unsigned long, std::__detail::_Hash_node<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, true>*, unsigned long) [71]
-----------------------------------------------
                0.00    0.05  109360/109360      std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&) <cycle 1> [9]
[29]     0.6    0.00    0.05  109360         swap_chains_2v(Assignment*, Solution) [29]
                0.00    0.02  109360/8387713     swap_chains(Assignment*, Solution, std::vector<int, std::allocator<int> >) [13]
                0.01    0.02  109360/218335      generate_k(int, int) [32]
-----------------------------------------------
                0.00    0.05   30000/30000       read_and_solve(std::function<Solution (Assignment*)>) [1]
[30]     0.6    0.00    0.05   30000         void std::__stable_sort_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [30]
                0.00    0.04   60000/60000       void std::__merge_sort_with_buffer<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [34]
                0.01    0.00   52694/124620      __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > > std::__move_merge<Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [44]
                0.00    0.00   30000/30000       void std::__merge_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, long, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, long, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [68]
-----------------------------------------------
                0.00    0.05  108975/108975      std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&) <cycle 1> [9]
[31]     0.6    0.00    0.05  108975         swap_chains_3v(Assignment*, Solution) [31]
                0.00    0.02  108975/8387713     swap_chains(Assignment*, Solution, std::vector<int, std::allocator<int> >) [13]
                0.00    0.02  108975/218335      generate_k(int, int) [32]
-----------------------------------------------
                0.00    0.02  108975/218335      swap_chains_3v(Assignment*, Solution) [31]
                0.01    0.02  109360/218335      swap_chains_2v(Assignment*, Solution) [29]
[32]     0.6    0.01    0.04  218335         generate_k(int, int) [32]
                0.01    0.00  548634/6635015     RandomGenerator::get_rand_int64() [20]
                0.01    0.00  545645/545645      std::pair<std::_Rb_tree_iterator<int>, bool> std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_insert_unique<int const&>(int const&) [48]
                0.01    0.00  218335/218335      std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_erase(std::_Rb_tree_node<int>*) [50]
                0.00    0.00  545645/545645      void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [63]
-----------------------------------------------
                              219086             std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&) <cycle 1> [9]
[33]     0.6    0.01    0.03  219086         LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) <cycle 1> [33]
                0.02    0.01  219086/219086      Assignment::init_can_from_to() [38]
                0.00    0.00  219086/25335595     fixed_zone_order_dp(Assignment const*) [19]
                0.00    0.00  219086/6301897     std::discrete_distribution<int>::param_type::_M_initialize() [37]
                0.00    0.00  219086/219090      std::function<Solution (Assignment*, Solution)>::function(std::function<Solution (Assignment*, Solution)> const&) [65]
                0.00    0.00  219086/438181      std::_Function_base::_Base_manager<Solution (*)(Assignment*, Solution)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [64]
                              219086             std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&) <cycle 1> [9]
-----------------------------------------------
                0.00    0.04   60000/60000       void std::__stable_sort_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [30]
[34]     0.5    0.00    0.04   60000         void std::__merge_sort_with_buffer<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [34]
                0.02    0.00  184620/184620      Edge const** std::__move_merge<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, Edge const**, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [43]
                0.01    0.00   71926/124620      __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > > std::__move_merge<Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [44]
                0.01    0.00  277420/277620      void std::__insertion_sort<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [49]
-----------------------------------------------
                0.00    0.04       1/1           calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
[35]     0.5    0.00    0.04       1         get_max_edges_index_bs(std::function<Solution (Assignment*)>, Assignment*) [35]
                0.00    0.04     680/85657       std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment const*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [7]
                0.00    0.00       1/3           get_max_edges_cnt(Assignment const*) [78]
                0.00    0.00       1/78975       Solution::score() [67]
-----------------------------------------------
                0.03    0.00 8169378/8169378     apply_all_swaps_2v(Assignment*, Solution) [10]
[36]     0.4    0.03    0.00 8169378         void std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::emplace_back<std::vector<int, std::allocator<int> > >(std::vector<int, std::allocator<int> >&&) [36]
-----------------------------------------------
                0.00    0.00  219086/6301897     LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) <cycle 1> [33]
                0.03    0.00 6082811/6301897     get_random_edge_weighted(GreedyManager*, std::vector<Edge const*, std::allocator<Edge const*> > const&) [21]
[37]     0.4    0.03    0.00 6301897         std::discrete_distribution<int>::param_type::_M_initialize() [37]
-----------------------------------------------
                0.02    0.01  219086/219086      LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) <cycle 1> [33]
[38]     0.4    0.02    0.01  219086         Assignment::init_can_from_to() [38]
                0.01    0.00       1/1           std::vector<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >, std::allocator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > > >::_M_fill_insert(__gnu_cxx::__normal_iterator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >*, std::vector<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >, std::allocator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > > > >, unsigned long, std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > const&) [52]
-----------------------------------------------
                0.02    0.00      33/33          std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [40]
[39]     0.3    0.02    0.00      33         solve_simple(Assignment*) [39]
                0.00    0.00    4950/6635015     RandomGenerator::get_rand_int64() [20]
                0.00    0.00    4879/9145333     void std::vector<Edge const*, std::allocator<Edge const*> >::emplace_back<Edge const*>(Edge const*&&) [27]
                0.00    0.00      33/78975       Solution::score() [67]
-----------------------------------------------
                0.00    0.02      33/33          run_main(std::function<Solution (Assignment*)>, Assignment*, bool, int) [41]
[40]     0.3    0.00    0.02      33         std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [40]
                0.02    0.00      33/33          solve_simple(Assignment*) [39]
-----------------------------------------------
                0.00    0.02       1/1           std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&) [2]
[41]     0.3    0.00    0.02       1         run_main(std::function<Solution (Assignment*)>, Assignment*, bool, int) [41]
                0.00    0.02      33/33          std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [40]
                0.00    0.00      33/78975       Solution::score() [67]
-----------------------------------------------
                0.02    0.00 1702028/1702028     read_and_solve(std::function<Solution (Assignment*)>) [1]
[42]     0.3    0.02    0.00 1702028         void std::vector<Edge*, std::allocator<Edge*> >::emplace_back<Edge*>(Edge*&&) [42]
-----------------------------------------------
                0.02    0.00  184620/184620      void std::__merge_sort_with_buffer<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [34]
[43]     0.3    0.02    0.00  184620         Edge const** std::__move_merge<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, Edge const**, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [43]
-----------------------------------------------
                0.01    0.00   52694/124620      void std::__stable_sort_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [30]
                0.01    0.00   71926/124620      void std::__merge_sort_with_buffer<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [34]
[44]     0.3    0.02    0.00  124620         __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > > std::__move_merge<Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [44]
-----------------------------------------------
                0.02    0.00      22/22          Assignment::read_data() [22]
[45]     0.3    0.02    0.00      22         void std::vector<Edge, std::allocator<Edge> >::_M_realloc_insert<Edge>(__gnu_cxx::__normal_iterator<Edge*, std::vector<Edge, std::allocator<Edge> > >, Edge&&) [45]
-----------------------------------------------
                                                 <spontaneous>
[46]     0.2    0.02    0.00                 LocalManager::local_step(std::vector<int, std::allocator<int> >) [46]
-----------------------------------------------
                0.00    0.00     200/3404457     Assignment::read_data() [22]
                0.01    0.00 3404257/3404457     std::__detail::_Map_base<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true>, true>::operator[](std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [28]
[47]     0.1    0.01    0.00 3404457         std::_Hashtable<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true> >::_M_find_before_node(unsigned long, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, unsigned long) const [47]
-----------------------------------------------
                0.01    0.00  545645/545645      generate_k(int, int) [32]
[48]     0.1    0.01    0.00  545645         std::pair<std::_Rb_tree_iterator<int>, bool> std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_insert_unique<int const&>(int const&) [48]
-----------------------------------------------
                0.00    0.00     200/277620      read_and_solve(std::function<Solution (Assignment*)>) [1]
                0.01    0.00  277420/277620      void std::__merge_sort_with_buffer<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [34]
[49]     0.1    0.01    0.00  277620         void std::__insertion_sort<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [49]
-----------------------------------------------
                              545645             std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_erase(std::_Rb_tree_node<int>*) [50]
                0.01    0.00  218335/218335      generate_k(int, int) [32]
[50]     0.1    0.01    0.00  218335+545645  std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_erase(std::_Rb_tree_node<int>*) [50]
                              545645             std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_erase(std::_Rb_tree_node<int>*) [50]
-----------------------------------------------
                0.01    0.00     751/751         apply_all_swaps_2v(Assignment*, Solution) [10]
[51]     0.1    0.01    0.00     751         std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::~vector() [51]
-----------------------------------------------
                0.01    0.00       1/1           Assignment::init_can_from_to() [38]
[52]     0.1    0.01    0.00       1         std::vector<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >, std::allocator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > > >::_M_fill_insert(__gnu_cxx::__normal_iterator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >*, std::vector<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >, std::allocator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > > > >, unsigned long, std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > const&) [52]
-----------------------------------------------
                                                 <spontaneous>
[53]     0.1    0.01    0.00                 dp_construct_solution_from(Assignment const*, std::vector<std::vector<Edge const*, std::allocator<Edge const*> >, std::allocator<std::vector<Edge const*, std::allocator<Edge const*> > > >, int) [53]
-----------------------------------------------
                                                 <spontaneous>
[54]     0.1    0.01    0.00                 swap_anyway(Assignment const*, int, int) [54]
-----------------------------------------------
                0.00    0.00  770857/770857      get_greedy_path(GreedyManager*) [5]
[62]     0.0    0.00    0.00  770857         void std::vector<Edge const*, std::allocator<Edge const*> >::_M_realloc_insert<Edge const* const&>(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const* const&) [62]
-----------------------------------------------
                0.00    0.00  545645/545645      generate_k(int, int) [32]
[63]     0.0    0.00    0.00  545645         void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&) [63]
-----------------------------------------------
                0.00    0.00       1/438181      calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
                0.00    0.00       1/438181      std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&) [2]
                0.00    0.00       3/438181      std::vector<std::function<Solution (Assignment*, Solution)>, std::allocator<std::function<Solution (Assignment*, Solution)> > >::~vector() [122]
                0.00    0.00  219086/438181      LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) <cycle 1> [33]
                0.00    0.00  219090/438181      std::function<Solution (Assignment*, Solution)>::function(std::function<Solution (Assignment*, Solution)> const&) [65]
[64]     0.0    0.00    0.00  438181         std::_Function_base::_Base_manager<Solution (*)(Assignment*, Solution)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [64]
-----------------------------------------------
                0.00    0.00       1/219090      calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
                0.00    0.00       3/219090      std::vector<std::function<Solution (Assignment*, Solution)>, std::allocator<std::function<Solution (Assignment*, Solution)> > >::vector(std::initializer_list<std::function<Solution (Assignment*, Solution)> >, std::allocator<std::function<Solution (Assignment*, Solution)> > const&) [121]
                0.00    0.00  219086/219090      LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) <cycle 1> [33]
[65]     0.0    0.00    0.00  219090         std::function<Solution (Assignment*, Solution)>::function(std::function<Solution (Assignment*, Solution)> const&) [65]
                0.00    0.00  219090/438181      std::_Function_base::_Base_manager<Solution (*)(Assignment*, Solution)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [64]
-----------------------------------------------
                0.00    0.00   85657/85657       greedy(Assignment const*) [6]
[66]     0.0    0.00    0.00   85657         std::vector<bool, std::allocator<bool> >::_M_fill_insert(std::_Bit_iterator, unsigned long, bool) [66]
-----------------------------------------------
                0.00    0.00       1/78975       get_max_edges_index_bs(std::function<Solution (Assignment*)>, Assignment*) [35]
                0.00    0.00       1/78975       get_max_edges_index_ls(std::function<Solution (Assignment*)>, Assignment*, int, int) [17]
                0.00    0.00       1/78975       std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&) [2]
                0.00    0.00       1/78975       read_and_solve(std::function<Solution (Assignment*)>) [1]
                0.00    0.00      33/78975       run_main(std::function<Solution (Assignment*)>, Assignment*, bool, int) [41]
                0.00    0.00      33/78975       solve_simple(Assignment*) [39]
                0.00    0.00   78905/78975       run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [4]
[67]     0.0    0.00    0.00   78975         Solution::score() [67]
-----------------------------------------------
                0.00    0.00   30000/30000       void std::__stable_sort_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [30]
[68]     0.0    0.00    0.00   30000         void std::__merge_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, long, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, long, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [68]
-----------------------------------------------
                0.00    0.00     751/751         apply_all_swaps_2v(Assignment*, Solution) [10]
[69]     0.0    0.00    0.00     751         std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::reserve(unsigned long) [69]
-----------------------------------------------
                0.00    0.00       9/401         void std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_realloc_insert<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&>(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [75]
                0.00    0.00     191/401         Assignment::read_data() [22]
                0.00    0.00     201/401         std::__detail::_Map_base<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true>, true>::operator[](std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [28]
[70]     0.0    0.00    0.00     401         void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char*>(char*, char*, std::forward_iterator_tag) [70]
-----------------------------------------------
                0.00    0.00     201/201         std::__detail::_Map_base<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true>, true>::operator[](std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [28]
[71]     0.0    0.00    0.00     201         std::_Hashtable<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true> >::_M_insert_unique_node(unsigned long, unsigned long, std::__detail::_Hash_node<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, true>*, unsigned long) [71]
-----------------------------------------------
                0.00    0.00     200/200         read_and_solve(std::function<Solution (Assignment*)>) [1]
[72]     0.0    0.00    0.00     200         std::vector<std::vector<Edge const*, std::allocator<Edge const*> >, std::allocator<std::vector<Edge const*, std::allocator<Edge const*> > > >::_M_default_append(unsigned long) [72]
-----------------------------------------------
                0.00    0.00     200/200         read_and_solve(std::function<Solution (Assignment*)>) [1]
[73]     0.0    0.00    0.00     200         void std::__inplace_stable_sort<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>) [73]
-----------------------------------------------
                0.00    0.00     197/197         Assignment::read_data() [22]
[74]     0.0    0.00    0.00     197         void std::vector<Airport*, std::allocator<Airport*> >::_M_realloc_insert<Airport*>(__gnu_cxx::__normal_iterator<Airport**, std::vector<Airport*, std::allocator<Airport*> > >, Airport*&&) [74]
-----------------------------------------------
                0.00    0.00       9/9           Assignment::read_data() [22]
[75]     0.0    0.00    0.00       9         void std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_realloc_insert<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&>(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [75]
                0.00    0.00       9/401         void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char*>(char*, char*, std::forward_iterator_tag) [70]
-----------------------------------------------
                0.00    0.00       9/9           Assignment::read_data() [22]
[76]     0.0    0.00    0.00       9         void std::vector<std::vector<Airport*, std::allocator<Airport*> >, std::allocator<std::vector<Airport*, std::allocator<Airport*> > > >::_M_realloc_insert<std::vector<Airport*, std::allocator<Airport*> > >(__gnu_cxx::__normal_iterator<std::vector<Airport*, std::allocator<Airport*> >*, std::vector<std::vector<Airport*, std::allocator<Airport*> >, std::allocator<std::vector<Airport*, std::allocator<Airport*> > > > >, std::vector<Airport*, std::allocator<Airport*> >&&) [76]
-----------------------------------------------
                0.00    0.00       1/7           std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&) [2]
                0.00    0.00       3/7           calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
                0.00    0.00       3/7           std::function<Solution (Assignment*)>::function(std::function<Solution (Assignment*)> const&) [80]
[77]     0.0    0.00    0.00       7         std::_Function_base::_Base_manager<Solution (*)(Assignment const*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [77]
-----------------------------------------------
                0.00    0.00       1/3           get_max_edges_index_bs(std::function<Solution (Assignment*)>, Assignment*) [35]
                0.00    0.00       2/3           calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
[78]     0.0    0.00    0.00       3         get_max_edges_cnt(Assignment const*) [78]
-----------------------------------------------
                0.00    0.00       3/3           run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [4]
[79]     0.0    0.00    0.00       3         std::vector<Edge const*, std::allocator<Edge const*> >::operator=(std::vector<Edge const*, std::allocator<Edge const*> > const&) [79]
-----------------------------------------------
                0.00    0.00       3/3           calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [3]
[80]     0.0    0.00    0.00       3         std::function<Solution (Assignment*)>::function(std::function<Solution (Assignment*)> const&) [80]
                0.00    0.00       3/7           std::_Function_base::_Base_manager<Solution (*)(Assignment const*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [77]
-----------------------------------------------
                0.00    0.00       2/2           run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [4]
[81]     0.0    0.00    0.00       2         std::_Function_base::_Base_manager<main::{lambda(Assignment*)#1}>::_M_manager(std::_Any_data&, std::_Function_base::_Base_manager<main::{lambda(Assignment*)#1}> const&, std::_Manager_operation) [81]
-----------------------------------------------
                0.00    0.00       1/1           __libc_csu_init [134]
[82]     0.0    0.00    0.00       1         _GLOBAL__sub_I__Z14get_time_in_msNSt6chrono10time_pointINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEEE [82]
-----------------------------------------------
                0.00    0.00       1/1           std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&) [2]
[83]     0.0    0.00    0.00       1         std::_Function_base::_Base_manager<Solution (*)(Assignment*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [83]
-----------------------------------------------
                0.00    0.00       1/1           Assignment::read_data() [22]
[84]     0.0    0.00    0.00       1         std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_default_append(unsigned long) [84]
-----------------------------------------------

 This table describes the call tree of the program, and was sorted by
 the total amount of time spent in each function and its children.

 Each entry in this table consists of several lines.  The line with the
 index number at the left hand margin lists the current function.
 The lines above it list the functions that called this function,
 and the lines below it list the functions this one called.
 This line lists:
     index	A unique number given to each element of the table.
		Index numbers are sorted numerically.
		The index number is printed next to every function name so
		it is easier to look up where the function is in the table.

     % time	This is the percentage of the `total' time that was spent
		in this function and its children.  Note that due to
		different viewpoints, functions excluded by options, etc,
		these numbers will NOT add up to 100%.

     self	This is the total amount of time spent in this function.

     children	This is the total amount of time propagated into this
		function by its children.

     called	This is the number of times the function was called.
		If the function called itself recursively, the number
		only includes non-recursive calls, and is followed by
		a `+' and the number of recursive calls.

     name	The name of the current function.  The index number is
		printed after it.  If the function is a member of a
		cycle, the cycle number is printed between the
		function's name and the index number.


 For the function's parents, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the function into this parent.

     children	This is the amount of time that was propagated from
		the function's children into this parent.

     called	This is the number of times this parent called the
		function `/' the total number of times the function
		was called.  Recursive calls to the function are not
		included in the number after the `/'.

     name	This is the name of the parent.  The parent's index
		number is printed after it.  If the parent is a
		member of a cycle, the cycle number is printed between
		the name and the index number.

 If the parents of the function cannot be determined, the word
 `<spontaneous>' is printed in the `name' field, and all the other
 fields are blank.

 For the function's children, the fields have the following meanings:

     self	This is the amount of time that was propagated directly
		from the child into the function.

     children	This is the amount of time that was propagated from the
		child's children to the function.

     called	This is the number of times the function called
		this child `/' the total number of times the child
		was called.  Recursive calls by the child are not
		listed in the number after the `/'.

     name	This is the name of the child.  The child's index
		number is printed after it.  If the child is a
		member of a cycle, the cycle number is printed
		between the name and the index number.

 If there are any cycles (circles) in the call graph, there is an
 entry for the cycle-as-a-whole.  This entry shows who called the
 cycle (as parents) and the members of the cycle (as children.)
 The `+' recursive calls entry shows the number of function calls that
 were internal to the cycle, and the calls entry for each member shows,
 for that member, how many times it was called from other members of
 the cycle.

Copyright (C) 2012-2018 Free Software Foundation, Inc.

Copying and distribution of this file, with or without modification,
are permitted in any medium without royalty provided the copyright
notice and this notice are preserved.

Index by function name

  [82] _GLOBAL__sub_I__Z14get_time_in_msNSt6chrono10time_pointINS_3_V212steady_clockENS_8durationIlSt5ratioILl1ELl1000000000EEEEEE [46] LocalManager::local_step(std::vector<int, std::allocator<int> >) [76] void std::vector<std::vector<Airport*, std::allocator<Airport*> >, std::allocator<std::vector<Airport*, std::allocator<Airport*> > > >::_M_realloc_insert<std::vector<Airport*, std::allocator<Airport*> > >(__gnu_cxx::__normal_iterator<std::vector<Airport*, std::allocator<Airport*> >*, std::vector<std::vector<Airport*, std::allocator<Airport*> >, std::allocator<std::vector<Airport*, std::allocator<Airport*> > > > >, std::vector<Airport*, std::allocator<Airport*> >&&)
  [32] generate_k(int, int)   [20] RandomGenerator::get_rand_int64() [72] std::vector<std::vector<Edge const*, std::allocator<Edge const*> >, std::allocator<std::vector<Edge const*, std::allocator<Edge const*> > > >::_M_default_append(unsigned long)
  [54] swap_anyway(Assignment const*, int, int) [33] LocalOptimizeManager::apply_random_optimization(Assignment*, Solution) [52] std::vector<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >, std::allocator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > > >::_M_fill_insert(__gnu_cxx::__normal_iterator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >*, std::vector<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > >, std::allocator<std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > > > >, unsigned long, std::vector<std::vector<Edge*, std::allocator<Edge*> >, std::allocator<std::vector<Edge*, std::allocator<Edge*> > > > const&)
  [13] swap_chains(Assignment*, Solution, std::vector<int, std::allocator<int> >) [16] SuitableEdgesIterator::get_next_suitable_edge(std::vector<bool, std::allocator<bool> > const&) [36] void std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::emplace_back<std::vector<int, std::allocator<int> > >(std::vector<int, std::allocator<int> >&&)
  [39] solve_simple(Assignment*) [67] Solution::score()   [69] std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::reserve(unsigned long)
   [1] read_and_solve(std::function<Solution (Assignment*)>) [47] std::_Hashtable<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true> >::_M_find_before_node(unsigned long, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&, unsigned long) const [51] std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > >::~vector()
  [29] swap_chains_2v(Assignment*, Solution) [71] std::_Hashtable<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true> >::_M_insert_unique_node(unsigned long, unsigned long, std::__detail::_Hash_node<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, true>*, unsigned long) [24] void std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > >::emplace_back<std::pair<Edge const*, Edge const*> >(std::pair<Edge const*, Edge const*>&&)
  [31] swap_chains_3v(Assignment*, Solution) [83] std::_Function_base::_Base_manager<Solution (*)(Assignment*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [26] std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > >::_M_fill_insert(__gnu_cxx::__normal_iterator<std::pair<Edge const*, Edge const*>*, std::vector<std::pair<Edge const*, Edge const*>, std::allocator<std::pair<Edge const*, Edge const*> > > >, unsigned long, std::pair<Edge const*, Edge const*> const&)
   [5] get_greedy_path(GreedyManager*) [64] std::_Function_base::_Base_manager<Solution (*)(Assignment*, Solution)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [66] std::vector<bool, std::allocator<bool> >::_M_fill_insert(std::_Bit_iterator, unsigned long, bool)
  [11] swap_chains_step(Assignment const*, Solution const&, std::vector<int, std::allocator<int> >) [77] std::_Function_base::_Base_manager<Solution (*)(Assignment const*)>::_M_manager(std::_Any_data&, std::_Any_data const&, std::_Manager_operation) [63] void std::vector<int, std::allocator<int> >::_M_realloc_insert<int const&>(__gnu_cxx::__normal_iterator<int*, std::vector<int, std::allocator<int> > >, int const&)
  [78] get_max_edges_cnt(Assignment const*) [81] std::_Function_base::_Base_manager<main::{lambda(Assignment*)#1}>::_M_manager(std::_Any_data&, std::_Function_base::_Base_manager<main::{lambda(Assignment*)#1}> const&, std::_Manager_operation) [70] void std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::_M_construct<char*>(char*, char*, std::forward_iterator_tag)
  [10] apply_all_swaps_2v(Assignment*, Solution) [7] std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment const*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [48] std::pair<std::_Rb_tree_iterator<int>, bool> std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_insert_unique<int const&>(int const&)
  [19] fixed_zone_order_dp(Assignment const*) [40] std::_Function_handler<Solution (Assignment*), Solution (*)(Assignment*)>::_M_invoke(std::_Any_data const&, Assignment*&&) [50] std::_Rb_tree<int, int, std::_Identity<int>, std::less<int>, std::allocator<int> >::_M_erase(std::_Rb_tree_node<int>*)
  [14] get_next_edge_random(GreedyManager*) [2] std::_Function_handler<Solution (Assignment*), main::{lambda(Assignment*)#1}>::_M_invoke(std::_Any_data const&, Assignment*&&) [28] std::__detail::_Map_base<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int>, std::allocator<std::pair<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const, int> >, std::__detail::_Select1st, std::equal_to<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::hash<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::__detail::_Mod_range_hashing, std::__detail::_Default_ranged_hash, std::__detail::_Prime_rehash_policy, std::__detail::_Hashtable_traits<true, false, true>, true>::operator[](std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)
  [25] get_least_visited_edge(GreedyManager*) [9] std::_Function_handler<Solution (Assignment*, Solution), Solution (*)(Assignment*, Solution)>::_M_invoke(std::_Any_data const&, Assignment*&&, Solution&&) [80] std::function<Solution (Assignment*)>::function(std::function<Solution (Assignment*)> const&)
  [35] get_max_edges_index_bs(std::function<Solution (Assignment*)>, Assignment*) [37] std::discrete_distribution<int>::param_type::_M_initialize() [65] std::function<Solution (Assignment*, Solution)>::function(std::function<Solution (Assignment*, Solution)> const&)
  [17] get_max_edges_index_ls(std::function<Solution (Assignment*)>, Assignment*, int, int) [18] std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>::operator()() [43] Edge const** std::__move_merge<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, Edge const**, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  [12] get_next_edge_weighted(GreedyManager*) [45] void std::vector<Edge, std::allocator<Edge> >::_M_realloc_insert<Edge>(__gnu_cxx::__normal_iterator<Edge*, std::vector<Edge, std::allocator<Edge> > >, Edge&&) [44] __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > > std::__move_merge<Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
   [4] run_multiple_solutions(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [84] std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_default_append(unsigned long) [49] void std::__insertion_sort<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  [21] get_random_edge_weighted(GreedyManager*, std::vector<Edge const*, std::allocator<Edge const*> > const&) [75] void std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > >::_M_realloc_insert<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&>(__gnu_cxx::__normal_iterator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >*, std::vector<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::allocator<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > > > >, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&) [68] void std::__merge_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, long, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, long, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
   [3] calibrate_max_edges_index(std::function<Solution (Assignment*)>, std::function<Solution (Assignment*, Solution)>, Assignment*) [42] void std::vector<Edge*, std::allocator<Edge*> >::emplace_back<Edge*>(Edge*&&) [73] void std::__inplace_stable_sort<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  [53] dp_construct_solution_from(Assignment const*, std::vector<std::vector<Edge const*, std::allocator<Edge const*> >, std::allocator<std::vector<Edge const*, std::allocator<Edge const*> > > >, int) [23] void std::vector<Airport*, std::allocator<Airport*> >::_M_realloc_insert<Airport* const&>(__gnu_cxx::__normal_iterator<Airport**, std::vector<Airport*, std::allocator<Airport*> > >, Airport* const&) [30] void std::__stable_sort_adaptive<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, long, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
   [6] greedy(Assignment const*) [74] void std::vector<Airport*, std::allocator<Airport*> >::_M_realloc_insert<Airport*>(__gnu_cxx::__normal_iterator<Airport**, std::vector<Airport*, std::allocator<Airport*> > >, Airport*&&) [34] void std::__merge_sort_with_buffer<__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}> >(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>, Edge const**, __gnu_cxx::__ops::_Iter_comp_iter<Assignment::init_edges()::{lambda(Edge const*, Edge const*)#1}>)
  [41] run_main(std::function<Solution (Assignment*)>, Assignment*, bool, int) [27] void std::vector<Edge const*, std::allocator<Edge const*> >::emplace_back<Edge const*>(Edge const*&&) [15] void std::shuffle<__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&>(__gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, __gnu_cxx::__normal_iterator<std::vector<int, std::allocator<int> >*, std::vector<std::vector<int, std::allocator<int> >, std::allocator<std::vector<int, std::allocator<int> > > > >, std::mersenne_twister_engine<unsigned long, 64ul, 312ul, 156ul, 31ul, 13043109905998158313ul, 29ul, 6148914691236517205ul, 17ul, 8202884508482404352ul, 37ul, 18444473444759240704ul, 43ul, 6364136223846793005ul>&)
  [38] Assignment::init_can_from_to() [62] void std::vector<Edge const*, std::allocator<Edge const*> >::_M_realloc_insert<Edge const* const&>(__gnu_cxx::__normal_iterator<Edge const**, std::vector<Edge const*, std::allocator<Edge const*> > >, Edge const* const&) [8] <cycle 1>
  [22] Assignment::read_data() [79] std::vector<Edge const*, std::allocator<Edge const*> >::operator=(std::vector<Edge const*, std::allocator<Edge const*> > const&)
