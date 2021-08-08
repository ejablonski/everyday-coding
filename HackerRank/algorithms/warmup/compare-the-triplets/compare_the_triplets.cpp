#include "compare_the_triplets.h"

namespace triplets
{
    std::vector<int> compute( std::vector<int> v_alice, std::vector<int> v_bob ) {
        std::vector<int> alice_n_bob{ 0, 0 };

        for( int i = 0; i < v_alice.size(); i++ ) {
            if( v_alice[i] > v_bob[i] ) {
                alice_n_bob[0]++;
            } else if( v_alice[i] < v_bob[i] ) {
                alice_n_bob[1]++;
            }
        }

        return alice_n_bob;
    }
}