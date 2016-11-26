#pragma once
template <class t>
class list
{
	t * data;
	int end;
	int beg;
public:
	list(int b = 0);
	void add(t&);
	bool isempty();
	bool isfull();
	void remove();
	void visit(void(*pf)(t &));
	~list();
};
template <class t>
list::list(int b)
{
	end = b;
	data = new t*[end];
	for (int i = 0; i < end; i++)
	{
		data[i] = NULL;
	}
	beg = 0;
}
template<class t>
void list::add(t& x)
{
	if (isempty() || isfull())
		cout << "\aNo space in the list\n";
	else
	{
		data[b] = new t;
		data[b] = x;
		b++;
	}
}
template<class t>
void list::remove()
{
	if (isempty())
		cout << "\aNothing to remove\n";
	else
	{
		delete data[beg];
		data[beg] = NULL;
		beg--;
	}
}
template<class t>
bool list::isempty()
{
	if (end == 0 || beg == 0)
		return true;
	else
		return false;
}
template<class t>
bool list::isfull()
{
	if (beg == end)
		return true;
	else
		return false;
}
template<class t>
void list::visit(void(*pf)(t &))
{
	if (isempty())
		cout << "\aNothing on the list\n";
	else
	{
		for (int i = 0; i < beg; i++)
		{
			pf(data[i]);
		}
	}
}
template<class t>
list::~list()
{
	for (int i = 0; i < beg; i++)
	{
		delete data[i];
	}
	delete[] data;
}