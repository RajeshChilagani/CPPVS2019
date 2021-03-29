#include "Main.h"

#include <chrono>
#include <string>
#include <iostream>
#include <fstream>
#include <ios>
#include "DataStructures/LinkedList.h"
#include "ProblemSolving/Strings.h"
#include "ProblemSolving/Arrays.h"
#include "ProblemSolving/Recursion.h"
#include <sstream>

struct TreeNode
{
	TreeNode(int i_Data)
		: Data(i_Data){}
	int Data;
	TreeNode* Left = nullptr;
	TreeNode* Right = nullptr;
};

bool Search(TreeNode* Root, int val)
{
	if (!Root)
		return false;
	if (Root->Data == val)
		return true;

	bool result = false;
	if (Root->Left)
		result = Search(Root->Left, val);
	if (!result)
	{
		if (Root->Right)
			result =Search(Root->Right, val);
	}

	return result;
}

int main()
{
	TreeNode* BTRoot = new TreeNode(2);
	TreeNode* BTRoot1 = new TreeNode(22);
	TreeNode* BTRoot2 = new TreeNode(23);
	TreeNode* BTRoot3 = new TreeNode(2);
	BTRoot->Left = BTRoot1;
	BTRoot->Right= BTRoot2;
	BTRoot1->Left = BTRoot3;
	bool res = Search(BTRoot, 2);
	std::stringstream ss;
	ss << "Ds,fpd12,12s";
	std::string word;
	std::getline(ss, word, ',');
	while (std::getline(ss, word, ','))
	{
		std::cout << word;
	}
	std::vector<int>* val = nullptr;
	for (int v : *val)
	{
		std::cout << val;
	}
	std::ifstream in("tet.txt");
	
	//check if file opened
	if (!in.is_open())
	{
		std::cout << "Unable to open file " << std::endl;
		return false;
	}
	std::unordered_map<int, int> MemMap;
	std::cout << GetNthFibNumber(15,MemMap);
	TestLinkedlist();
	std::string S("Rambo");
	ReverseString(S.c_str());
	auto startTime = std::chrono::system_clock::now();
	bool Ans = Strcmp("", "");
	auto EndTime = std::chrono::system_clock::now();
	std::chrono::duration<double> Elapsed = startTime - EndTime;
	std::cout <<"\n"<<Ans<<"Time:"<<Elapsed.count();
	std::vector<int> Nums{0,0,0,6,5,7,60,0};
	MoveZeroes(Nums);
	std::cout<<std::endl;
}