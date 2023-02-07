#include"Graph.h"
#include <chrono>
using namespace std::chrono;
int main()
{
	/*Graph g;
	g.addNode(6);
	g.addNode(5);
	g.addNode(4);
	g.addNode(3);
	g.addNode(2);
	g.addNode(1);
	g.addEdge(1, 4, 4);
	g.addEdge(1, 2, 3);
	g.addEdge(1, 3, 5);
	g.addEdge(2, 5, 8);
	g.addEdge(4, 5, 2);
	g.addEdge(4, 3, 1);
	g.addEdge(4, 6, 7);
	//g.boruvkinAlgoritam();
	//cout << "Najmanja grana cvora 1 je :" << g.start->minEdge->weight << endl;
	g.primAlgoritam();
	cout << "-------PRINT METODA---------" << endl;
	g.print();*/
	Graph g1, g2, g3, g4;
	for (int i = 0; i < 10; i++) //10 cvorova
	{
		g1.addNode(i);
	}
	for (int i = 0; i < 10; i++)
	{
		g1.addEdge(rand() % 10, rand() % 10, rand() % 100); //10 grana
	}
	auto start = high_resolution_clock::now();
	g1.primAlgoritam(); //10 grana
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 10 cvorova 10 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g1.boruvkinAlgoritam(); //10 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 10 cvorova 10 grana " << duration.count() << "us" << endl;


	for (int i = 0; i < 10; i++)
	{
		g1.addEdge(rand() % 10, rand() % 10, rand() % 100); //20 grana
	}
	start = high_resolution_clock::now();
	g1.primAlgoritam();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 10 cvorova 20 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g1.boruvkinAlgoritam();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 10 cvorova 20 grana " << duration.count() << "us" << endl;
	for (int i = 0; i < 30; i++)
	{
		g1.addEdge(rand() % 10, rand() % 10, rand() % 100); //50 grana
	}
	start = high_resolution_clock::now();
	g1.primAlgoritam();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 10 cvorova 50 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g1.boruvkinAlgoritam();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 10 cvorova 50 grana " << duration.count() << "us" << endl;
	for (int i = 0; i < 50; i++)
	{
		g1.addEdge(rand() % 10, rand() % 10, rand() % 100); //100 grana
	}
	start = high_resolution_clock::now();
	g1.primAlgoritam();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 10 cvorova 100 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g1.boruvkinAlgoritam();
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 10 cvorova 100 grana " << duration.count() << "us" << endl;




	for (int i = 0; i < 100; i++) //100 cvorova
	{
		g2.addNode(i);
	}
	for (int i = 0; i < 100; i++)
	{
		g2.addEdge(rand() % 10, rand() % 10, rand() % 100); //100 grana
	}
	start = high_resolution_clock::now();
	g2.primAlgoritam(); //100 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 100 cvorova 100 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g2.boruvkinAlgoritam(); //100 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 100 cvorova 100 grana " << duration.count() << "us" << endl;
	for (int i = 0; i < 100; i++)
	{
		g2.addEdge(rand() % 10, rand() % 10, rand() % 100); //200 grana
	}
	start = high_resolution_clock::now();
	g2.primAlgoritam(); //200 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 100 cvorova 200 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g2.boruvkinAlgoritam(); //200 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 100 cvorova 200 grana " << duration.count() << "us" << endl;
	for (int i = 0; i < 300; i++)
	{
		g2.addEdge(rand() % 10, rand() % 10, rand() % 100); //500 grana
	}
	start = high_resolution_clock::now();
	g2.primAlgoritam(); //500 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 100 cvorova 500 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g2.boruvkinAlgoritam(); //200 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 100 cvorova 500 grana " << duration.count() << "us" << endl;

	for (int i = 0; i < 500; i++)
	{
		g2.addEdge(rand() % 10, rand() % 10, rand() % 100); //1000 grana
	}
	start = high_resolution_clock::now();
	g2.primAlgoritam(); //1000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 100 cvorova 1000 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g2.boruvkinAlgoritam(); //1000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 100 cvorova 1000 grana " << duration.count() << "us" << endl;




	for (int i = 0; i < 1000; i++) //1000 cvorova
	{
		g3.addNode(i);
	}
	for (int i = 0; i < 1000; i++)
	{
		g3.addEdge(rand() % 10, rand() % 10, rand() % 100); //1000 grana
	}
	start = high_resolution_clock::now();
	g3.primAlgoritam(); //1000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 1000 cvorova 1000 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g3.boruvkinAlgoritam(); //1000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 1000 cvorova 1000 grana " << duration.count() << "us" << endl;

	for (int i = 0; i < 1000; i++)
	{
		g3.addEdge(rand() % 10, rand() % 10, rand() % 100); //2000 grana
	}
	start = high_resolution_clock::now();
	g3.primAlgoritam(); //2000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 1000 cvorova 2000 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g3.boruvkinAlgoritam(); //2000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 1000 cvorova 2000 grana " << duration.count() << "us" << endl;

	for (int i = 0; i < 3000; i++)
	{
		g3.addEdge(rand() % 10, rand() % 10, rand() % 100); //5000 grana
	}
	start = high_resolution_clock::now();
	g3.primAlgoritam(); //5000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 1000 cvorova 5000 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g3.boruvkinAlgoritam(); //5000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 1000 cvorova 5000 grana " << duration.count() << "us" << endl;
	for (int i = 0; i < 5000; i++)
	{
		g3.addEdge(rand() % 10, rand() % 10, rand() % 100); //10000 grana
	}
	start = high_resolution_clock::now();
	g3.primAlgoritam(); //10000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 1000 cvorova 10000 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g3.boruvkinAlgoritam(); //10000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 1000 cvorova 10000 grana " << duration.count() << "us" << endl;

	


	for (int i = 0; i < 10000; i++) //10000 cvorova
	{
		g4.addNode(i);
	}
	for (int i = 0; i < 10000; i++)
	{
		g4.addEdge(rand() % 10, rand() % 10, rand() % 100); //10000 grana
	}
	start = high_resolution_clock::now();
	g4.primAlgoritam(); //10000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 10000 cvorova 10000 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g4.boruvkinAlgoritam(); //10000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 10000 cvorova 10000 grana " << duration.count() << "us" << endl;
	for (int i = 0; i < 10000; i++)
	{
		g4.addEdge(rand() % 10, rand() % 10, rand() % 100); //20000 grana
	}
	start = high_resolution_clock::now();
	g4.primAlgoritam(); //20000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 10000 cvorova 20000 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g4.boruvkinAlgoritam(); //20000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 10000 cvorova 20000 grana " << duration.count() << "us" << endl;

	for (int i = 0; i < 300000; i++)
	{
		g4.addEdge(rand() % 10, rand() % 10, rand() % 100); //50000 grana
	}
	start = high_resolution_clock::now();
	g4.primAlgoritam(); //50000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 10000 cvorova 50000 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g4.boruvkinAlgoritam(); //50000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 10000 cvorova 50000 grana " << duration.count() << "us" << endl;
	
	for (int i = 0; i < 50000; i++)
	{
		g4.addEdge(rand() % 10, rand() % 10, rand() % 100); //100000 grana
	}
	start = high_resolution_clock::now();
	g4.primAlgoritam(); //100000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Primovog algoritma za 10000 cvorova 100000 grana " << duration.count() << "us" << endl;

	start = high_resolution_clock::now();
	g4.boruvkinAlgoritam(); //100000 grana
	stop = high_resolution_clock::now();
	duration = duration_cast<microseconds>(stop - start);
	cout << "Vreme izvrsenja Boruvka algoritma za 10000 cvorova 100000 grana " << duration.count() << "us" << endl;
	return 0;
}