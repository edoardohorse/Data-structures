#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include "Map_for_test.h"

using testing::Eq;
using namespace NMapTest;

class MapTest: public testing::Test{
public:
	Map<char,int,26>* m = new Map<char, int, 26>;
	Map<std::string,int>* m2 = new Map<std::string, int>;
    MapTest(){

	    // appallottolerebbero
	    m->insert('a',2);
	    m->insert('p',2);
	    m->insert('l',3);
	    m->insert('o',3);
	    m->insert('t',2);
	    m->insert('e',3);
	    m->insert('r',2);
	    m->insert('b',2);

	    m2->insert("BA16",1);
/*	    FILE *fp;
	    char buffer [100];
	    fp = fopen ("myfile.txt" , "r");
	    if (fp == NULL) perror ("Error opening file");
	    else
	    {
		    while ( ! feof (fp) )
		    {
			    if ( fgets (buffer , 100 , fp) == NULL ) break;
//			    fputs (buffer , stdout);
			    m2->insert(buffer,0);
		    }
		    fclose (fp);
	    }
*/

    }
    ~MapTest(){
	    delete m,m2;
    }
};

TEST_F(MapTest, Has){
	ASSERT_TRUE(m->has('a'));
	ASSERT_TRUE(m->has('b'));
	ASSERT_FALSE(m->has('i'));
	ASSERT_FALSE(m->has('c'));
}
TEST_F(MapTest, Insert){}

TEST_F(MapTest, Remove){
	ASSERT_TRUE(m->has('a'));
	ASSERT_EQ(m->get('a'), 2);

	m->remove('a');
	ASSERT_FALSE(m->has('a'));
	m->insert('a',2);

	ASSERT_TRUE(m->has('a'));
	ASSERT_EQ(m->get('a'), 2);

}
TEST_F(MapTest, Get){
	ASSERT_EQ(m->get('a'),2);
	ASSERT_EQ(m->get('p'),2);
	ASSERT_EQ(m->get('l'),3);
	ASSERT_EQ(m->get('o'),3);
	ASSERT_EQ(m->get('t'),2);
	ASSERT_EQ(m->get('e'),3);
	ASSERT_EQ(m->get('r'),2);
	ASSERT_EQ(m->get('b'),2);

}

TEST_F(MapTest, Set){
	ASSERT_EQ(m->get('a'), 2);

	m->set('a',7);
	ASSERT_EQ(m->get('a'),7);
	m->set('a',2);

	ASSERT_EQ(m->get('a'), 2);


}

