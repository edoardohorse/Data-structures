#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../ListCursor.h"

using testing::Eq;
using namespace NListCursorTest;

class ClassDeclaration: public testing::Test{
public:

	ListCursor<char>* ls = new ListCursor<char>;

    ClassDeclaration(){

    }
    ~ClassDeclaration(){}
};

TEST_F(ClassDeclaration, Empty){}

TEST_F(ClassDeclaration, First){}

TEST_F(ClassDeclaration, Last){}

TEST_F(ClassDeclaration, Next){}

TEST_F(ClassDeclaration, Get){}

TEST_F(ClassDeclaration, Set){}

TEST_F(ClassDeclaration, Move){}

TEST_F(ClassDeclaration, Insert){}

TEST_F(ClassDeclaration, Remove){}

TEST_F(ClassDeclaration, Previous){}

