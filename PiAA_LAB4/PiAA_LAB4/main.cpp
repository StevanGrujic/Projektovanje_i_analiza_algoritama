#include<iostream>
#include "FibonacciHeap.h"
#include"BinomialHeap.h"
using namespace std;
#include <chrono>
using namespace std::chrono;

int main()
{
	BinomialHeap* heap1 = new BinomialHeap();
	BinomialHeap* heap2 = new BinomialHeap();
	BinomialHeap* heap3 = new BinomialHeap();
	BinomialHeap* heap4 = new BinomialHeap();
	BinomialHeap* heap5 = new BinomialHeap();

	FibonacciHeap* heap6 = new FibonacciHeap();
	FibonacciHeap* heap7 = new FibonacciHeap();
	FibonacciHeap* heap8 = new FibonacciHeap();
	FibonacciHeap* heap9 = new FibonacciHeap();
	FibonacciHeap* heap10 = new FibonacciHeap();


	//PRVI HEAP
	for (int i = 0; i < 10; i++)
	{
		BinomialNode* node1 = heap1->CreateNode(rand()%10000);
		heap1->Insert(node1);
	}
	auto start = high_resolution_clock::now();
	int c = rand() % 10000;
	heap1->Insert(new BinomialNode(c));
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert1_BinomniHeap: " << duration.count() <<"us"<< endl;

	start = high_resolution_clock::now();
	heap1->ExtractMin(heap1->startNode);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Extract1_BinomniHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	heap1->DeleteNode(41);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete1_BinomniHeap: " << duration.count() << "us" << endl;

	//DRUGI HEAP
	for (int i = 0; i < 100; i++)
	{
		BinomialNode* node1 = heap2->CreateNode(rand() % 10000);
		heap2->Insert(node1);
	}
	start = high_resolution_clock::now();
	for (int i = 0; i < 10; i++)
	{
		BinomialNode* node1 = heap2->CreateNode(rand() % 10000);
		heap2->Insert(node1);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert2_BinomniHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 10; i++)
	{
		heap2->ExtractMin(heap2->startNode);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_ExtractMin2_BinomniHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 10; i++)
	{
		heap2->DeleteNode(rand()%10000);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete2_BinomniHeap: " << duration.count() << "us" << endl;


	//TRECI HEAP
	for (int i = 0; i < 1000; i++)
	{
		BinomialNode* node1 = heap3->CreateNode(rand() % 10000);
		heap3->Insert(node1);
	}
	start = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		BinomialNode* node1 = heap3->CreateNode(rand() % 10000);
		heap3->Insert(node1);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert3_BinomniHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		heap3->ExtractMin(heap3->startNode);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_ExtractMin3_BinomniHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		heap3->DeleteNode(rand()%100);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete3_BinomniHeap: " << duration.count() << "us" << endl;

	//CETVRTI HEAP
	for (int i = 0; i < 10000; i++)
	{
		BinomialNode* node1 = heap4->CreateNode(rand() % 10000);
		heap4->Insert(node1);
	}
	start = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		BinomialNode* node1 = heap4->CreateNode(rand() % 10000);
		heap4->Insert(node1);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert4_BinomniHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		heap4->ExtractMin(heap4->startNode);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_ExtractMin4_BinomniHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		heap4->DeleteNode(rand() % 100);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete4_BinomniHeap: " << duration.count() << "us" << endl;

	//PETI HEAP
	/*for (int i = 0; i < 100000; i++)
	{
		BinomialNode* node1 = heap5->CreateNode(rand() % 10000);
		heap5->Insert(node1);
	}
	start = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		BinomialNode* node1 = heap5->CreateNode(rand() % 10000);
		heap5->Insert(node1);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert5_BinomniHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		heap5->ExtractMin(heap5->startNode);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_ExtractMin5_BinomniHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		heap5->DeleteNode(rand() % 100);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete5_BinomniHeap: " << duration.count() << "us" << endl;
	heap5->PrintRootNodes();
	*/


	cout << endl;
	cout << endl;


	//PRVI HEAP
	for (int i = 0; i < 10; i++)
	{
		heap6->Insert(rand() % 10000);
	}
	start = high_resolution_clock::now();
	c = rand() % 10000;
	heap6->Insert(c);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert1_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	heap6->ExtractMin();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Extract1_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	heap6->DeleteNode(41);
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete1_FibonacciHeap: " << duration.count() << "us" << endl;

	//DRUGI HEAP
	for (int i = 0; i < 100; i++)
	{
		heap7->Insert(rand() % 10000);
	}
	start = high_resolution_clock::now();
	for (int i = 0; i < 10; i++)
	{
		heap7->Insert(rand() % 10000);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert2_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 10; i++)
	{
		heap7->ExtractMin();
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_ExtractMin2_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 10; i++)
	{
		heap7->DeleteNode(rand() % 10000);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete2_FibonacciHeap: " << duration.count() << "us" << endl;


	//TRECI HEAP
	for (int i = 0; i < 1000; i++)
	{
		heap8->Insert(rand() % 10000);
	}
	start = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		heap8->Insert(rand() % 10000);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert3_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		heap8->ExtractMin();
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_ExtractMin3_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 100; i++)
	{
		heap8->DeleteNode(rand() % 100);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete3_FibonacciHeap: " << duration.count() << "us" << endl;

	//CETVRTI HEAP
	for (int i = 0; i < 10000; i++)
	{
		heap9->Insert(rand() % 10000);
	}
	start = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		heap9->Insert(rand() % 10000);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert4_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		heap9->ExtractMin();
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_ExtractMin4_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 1000; i++)
	{
		heap9->DeleteNode(rand() % 100);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete4_FibonacciHeap: " << duration.count() << "us" << endl;
	/*heap9->PrintRootNodes();
	heap9->ExtractMin();
	heap9->PrintRootNodes();
	heap9->ExtractMin();
	heap9->PrintRootNodes();
	heap9->ExtractMin();
	heap9->PrintRootNodes();*/

	//PETI HEAP
	/*for (int i = 0; i < 100000; i++)
	{
		heap10->Insert(rand() % 10000);
	}
	start = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		heap10->Insert(rand() % 10000);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Insert5_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		heap10->ExtractMin();
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_ExtractMin5_FibonacciHeap: " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	for (int i = 0; i < 10000; i++)
	{
		heap10->DeleteNode(rand() % 100);
	}
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja_Delete5_FibonacciHeap: " << duration.count() << "us" << endl;*/
	return 0;
}