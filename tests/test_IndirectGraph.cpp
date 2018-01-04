#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "IndirectGraph_for_test.h"

using namespace NIndirectGraphTest;
using testing::Eq;

class GraphTest: public testing::Test{
public:
	Graph<7>* g = new Graph<7>;
	NIndirectGraphTest::Node cucina   = 0;
	NIndirectGraphTest::Node salone   = 1;
	NIndirectGraphTest::Node bagnoP   = 2;
	NIndirectGraphTest::Node stanzaT  = 3;
	NIndirectGraphTest::Node bagnoG   = 4;
	NIndirectGraphTest::Node stanzaG  = 5;
	NIndirectGraphTest::Node stanzaE  = 6;

	GraphTest(){


		g->insertNode(cucina);
		g->insertNode(salone);
		g->insertNode(bagnoP);
		g->insertNode(stanzaT);
		g->insertNode(bagnoG);
		g->insertNode(stanzaG);
		g->insertNode(stanzaE);

		g->insertLink(cucina,salone);
		g->insertLink(cucina,bagnoP);
		g->insertLink(bagnoP,salone);
		g->insertLink(salone,stanzaT);
		g->insertLink(salone,bagnoG);
		g->insertLink(salone,stanzaG);
		g->insertLink(salone,stanzaE);



	}
	~GraphTest(){
		delete g;
	}
};

TEST_F(GraphTest, isEmpty){
	auto tmp = new Graph<5>;
	ASSERT_TRUE(tmp->isEmpty());
	ASSERT_FALSE(g->isEmpty());
	delete tmp;
}

TEST_F(GraphTest, insertNode){}
TEST_F(GraphTest, insertLink){}

TEST_F(GraphTest, removeNode){
	ASSERT_TRUE(g->hasNode(bagnoP));
	g->removeNode(bagnoP);
	ASSERT_FALSE(g->hasNode(bagnoP));
	g->insertNode(bagnoP);
	ASSERT_TRUE(g->hasNode(bagnoP));

}
TEST_F(GraphTest, removeLink){

	ASSERT_TRUE(g->hasLink(bagnoP, salone));
	ASSERT_TRUE(g->hasLink(salone, bagnoP));
	g->removeLink(bagnoP,salone);
	ASSERT_FALSE(g->hasLink(bagnoP, salone));
	ASSERT_FALSE(g->hasLink(salone, bagnoP));
	g->insertLink(bagnoP,salone);
	ASSERT_TRUE(g->hasLink(bagnoP, salone));
	ASSERT_TRUE(g->hasLink(salone, bagnoP));
}
TEST_F(GraphTest, getAdjacent){
	auto adjacents = g->adjacent(salone);
	auto tmp = adjacents->first();
	ASSERT_EQ(adjacents->get(tmp), cucina);

	tmp = adjacents->next(tmp);
	ASSERT_EQ(adjacents->get(tmp), bagnoP);

	tmp = adjacents->next(tmp);
	ASSERT_EQ(adjacents->get(tmp), stanzaT);

	tmp = adjacents->next(tmp);
	ASSERT_EQ(adjacents->get(tmp), bagnoG);

	tmp = adjacents->next(tmp);
	ASSERT_EQ(adjacents->get(tmp), stanzaG);

	tmp = adjacents->next(tmp);
	ASSERT_EQ(adjacents->get(tmp), stanzaE);
}

TEST_F(GraphTest, hasNode){
	ASSERT_TRUE(g->hasNode(cucina));
	ASSERT_TRUE(g->hasNode(salone));
	ASSERT_TRUE(g->hasNode(bagnoP));
	ASSERT_TRUE(g->hasNode(stanzaT));
	ASSERT_TRUE(g->hasNode(bagnoG));
	ASSERT_TRUE(g->hasNode(stanzaG));
	ASSERT_TRUE(g->hasNode(stanzaE));
}
TEST_F(GraphTest, hasLink){
	ASSERT_TRUE(g->hasLink(cucina,salone));
	ASSERT_TRUE(g->hasLink(cucina,bagnoP));
	ASSERT_TRUE(g->hasLink(bagnoP,salone));
	ASSERT_TRUE(g->hasLink(salone,stanzaT));
	ASSERT_TRUE(g->hasLink(salone,bagnoG));
	ASSERT_TRUE(g->hasLink(salone,stanzaG));
	ASSERT_TRUE(g->hasLink(salone,stanzaE));

	ASSERT_TRUE(g->hasLink(salone,cucina));
	ASSERT_TRUE(g->hasLink(bagnoP,cucina));
	ASSERT_TRUE(g->hasLink(salone,bagnoP));
	ASSERT_TRUE(g->hasLink(stanzaT,salone));
	ASSERT_TRUE(g->hasLink(bagnoG,salone));
	ASSERT_TRUE(g->hasLink(stanzaG,salone));
	ASSERT_TRUE(g->hasLink(stanzaE,salone));
}


/* cucina               salone
 * ---                  ---             ---
 * |0|  ←------------→  |1| ←---------→ \3\ stanzaT
 * ---                  ---        ↑    ---
 *  |                   ↑          |    ---
 *  ↓                   ↑          |--→ \4\ bagnoG
 * ---                  ↑          |    ---
 * |2| ←----------------→          |    ---
 * ---                             |--→ \5\ stanzaG
 * bagnoP                          |    ---
 *                                 |    ---
 *                                 |--→ \6\ stanzaE
 *                                      ---
 *
 * */