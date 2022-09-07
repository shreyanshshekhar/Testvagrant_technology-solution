#include<bits/stdc++.h>
using namespace std;

class ShoppingCart
{
	public:
	string pname;
	int costofitem;
	float gst;
	int quantity;
	
    ShoppingCart(){
	}
	ShoppingCart(string pname,int costofitem,float gst,int quantity)
	{
		this->pname = pname;
		this->costofitem = costofitem;
		this->gst = gst;
		this->quantity = quantity;
	}
	string maxgst(ShoppingCart ob[],int size)
	{
		string ans = "";
		float g = 0;
		for(int i = 0;i<size;i++)
		{
			if(ob[i].gst > g)
			{
				ans = ob[i].pname;
				g = ob[i].gst;
			}
		}
		return ans;
	}
	float totAmt(ShoppingCart ob[],int size)
	{
		float tot = 0;
		for(int i = 0;i<size;i++)
		{
			float netGst = (ob[i].costofitem * ob[i].quantity)*(ob[i].gst/100);
			tot += ((ob[i].costofitem*ob[i].quantity)+netGst);
		}
		return tot;
	}
};
int main()
{
	ShoppingCart *c1 = new ShoppingCart[50];
	c1[0] = ShoppingCart("Leather wallet",1100,18,1);
	c1[1] = ShoppingCart("Umbrella",900,12,2);
	c1[2] = ShoppingCart("Cigratte",200,28,3);
	c1[3] = ShoppingCart("Honey",100,0,4);
	cout<<"Total Amount = "<<c1[0].totAmt(c1,4)<<endl;
	cout<<"Product for which GST is paid maximum : "<<c1[0].maxgst(c1,4)<<endl;
	return 0;
}
