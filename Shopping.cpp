#include <iostream>
#include <vector>
using namespace std;

class Shopping_cart;

class cart_item {
public:
    int productid;
    std::string name;
    int price;
    int quantity;

    cart_item(int productid, std::string name, int price, int quantity) : productid(productid), name(name), price(price), quantity(quantity) {
    }
};

class Shopping_cart {
private:
    int cart_ID;
    int customerID;
    std::vector<cart_item> cart;

public:
    Shopping_cart(int customerID) : customerID(customerID) {
    }

    int getCart_ID() {
        return cart_ID;
    }

    void setCart_ID(int cart_ID) {
        this->cart_ID = cart_ID;
    }

    int getCustomerID() {
        return customerID;
    }

    void setCustomerID(int customerID) {
        this->customerID = customerID;
    }

    std::vector<cart_item>& getCart() {
        return cart;
    }

    void Add_item(int productid, std::string name, int price, int quantity) {
        for (int i = 0; i < cart.size(); i++) {
            if (cart[i].productid == productid) {
                std::cout << "Already Exists" << std::endl;
                return;
            }
        }
        cart.push_back(cart_item(productid, name, price, quantity));
    }

    void remove_item(int productid) {
        for (int i = 0; i < cart.size(); i++) {
            if (cart[i].productid == productid) {
                cart.erase(cart.begin() + i);
                return;
            }
        }
    }
};

class customer {
private:
    int customerID;
    std::vector<Shopping_cart> carts;

public:
    customer(int customerID) : customerID(customerID) {
    }

    int getCustomerID() {
        return customerID;
    }

    void setCustomerID(int customerID) {
        this->customerID = customerID;
    }

    std::vector<Shopping_cart>& getCarts() {
        return carts;
    }

    void Add_item_to_cart(int productid, std::string name, int price, int quantity, int Cart_id) {
        for (int i = 0; i < carts.size(); i++) {
            if (carts[i].getCart_ID() == Cart_id) {
                carts[i].Add_item(productid, name, price, quantity);
                return;
            }
        }
    }

    void Add(Shopping_cart cart) {
        carts.push_back(cart);
    }

    void remove(Shopping_cart cart) {
        for (int i = 0; i < carts.size(); i++) {
            if (carts[i].getCart_ID() == cart.getCart_ID()) {
                carts.erase(carts.begin() + i);
                return;
            }
        }
    }
};

class customer_manager {
private:
    std::vector<customer> customers;

public:
    void create_new_customer(int customerID) {
        customers.push_back(customer(customerID));
    }

    void Add_shopping_cart(int customerID, Shopping_cart cart) {
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].getCustomerID() == customerID) {
                customers[i].Add(cart);
                return;
            }
        }
    }

    void remove_shopping_cart(int customerID, int Cart_id) {
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].getCustomerID() == customerID) {
                for (int j = 0; j < customers[i].getCarts().size(); j++) {
                    if (customers[i].getCarts()[j].getCart_ID() == Cart_id) {
                        customers[i].remove(customers[i].getCarts()[j]);
                        return;
                    }
                }
            }
        }
    }
// Function to remove an item from a shopping cart
void remove_item_from_cart(int Cart_id, int customerID, int productid) {
    // Loop over all customers
    for (int i = 0; i < customers.size(); i++) {
        // Check if the current customer matches the given customerID
        if (customers[i].getCustomerID() == customerID) {
            // Get the shopping carts of the current customer
            std::vector<Shopping_cart>& carts = customers[i].getCarts();
            // Loop over all shopping carts of the current customer
            for (int j = 0; j < carts.size(); j++) {
                // Check if the current shopping cart matches the given Cart_id
                if (carts[j].getCart_ID() == Cart_id) {
                    // Remove the item with the given productid from the shopping cart
                    carts[j].remove_item(productid);
                    // Exit the function after the item has been removed
                    return;
                }
            }
        }
    }
}
    void display_Shopping_Carts(int customerID) {
        std::cout << "CustomerID : " << customerID << " has following carts" << std::endl;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].getCustomerID() == customerID) {
                for (int j = 0; j < customers[i].getCarts().size(); j++) {
                    std::cout << "CartID : " << customers[i].getCarts()[j].getCart_ID() << std::endl;
                    for (int k = 0; k < customers[i].getCarts()[j].getCart().size(); k++) {
                        std::cout << "ProductID : " << customers[i].getCarts()[j].getCart()[k].productid << std::endl;
                        std::cout << "Name : " << customers[i].getCarts()[j].getCart()[k].name << std::endl;
                        std::cout << "Price : " << customers[i].getCarts()[j].getCart()[k].price << std::endl;
                        std::cout << "Quantity : " << customers[i].getCarts()[j].getCart()[k].quantity << std::endl;
                    }
                }
            }
        }
    }

    void Add_item_to_cart(int customerID, int Cart_id, int productid, std::string name, int price, int quantity) {
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].getCustomerID() == customerID) {
                customers[i].Add_item_to_cart(productid, name, price, quantity, Cart_id);
                return;
            }
        }
    }

    Shopping_cart retrive(int customerID, int Cart_id) {
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].getCustomerID() == customerID) {
                for (int j = 0; j < customers[i].getCarts().size(); j++) {
                    if (customers[i].getCarts()[j].getCart_ID() == Cart_id) {
                        return customers[i].getCarts()[j];
                    }
                }
            }
        }
        return Shopping_cart(-1);
    }

    int total_value(int customerID) {
        int total_price = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (customers[i].getCustomerID() == customerID) {
                for (int j = 0; j < customers[i].getCarts().size(); j++) {
                    for (int k = 0; k < customers[i].getCarts()[j].getCart().size(); k++) {
                        total_price += customers[i].getCarts()[j].getCart()[k].price;
                    }
                }
            }
        }
        return total_price;
    }
};

int main() {
    customer_manager cm;
    cm.create_new_customer(1);
    cm.create_new_customer(2);
    cm.create_new_customer(3);
    Shopping_cart cart1(1);
    cart1.setCart_ID(1);
    cart1.Add_item(1, "Coke", 100, 1);
    cart1.Add_item(2, "Sprite", 200, 1);
    cart1.Add_item(3, "Pepsi", 300, 1);
    cm.Add_shopping_cart(1, cart1);
    Shopping_cart cart2(1);
    cart2.setCart_ID(2);
    cart2.Add_item(4, "Lays", 100, 1);
    cart2.Add_item(5, "Kurkure", 200, 1);
    cart2.Add_item(6, "Madangles", 300, 1);
    cm.Add_shopping_cart(1, cart2);
    Shopping_cart cart3(2);
    cart3.setCart_ID(3);
    cart3.Add_item(7, "item1", 100, 1);
    cart3.Add_item(8, "item2", 200, 1);
    cart3.Add_item(9, "item3", 300, 1);
    cm.Add_shopping_cart(2, cart3);
    std::cout << "customer 1 : " << cm.total_value(1) << std::endl;
    Shopping_cart cart4(3);
    cart4.setCart_ID(4);
    cart4.Add_item(1, "item1", 300, 1);
    cart4.Add_item(2, "item2", 5000, 1);
    cart4.Add_item(3, "item3", 191900, 1);
    cm.Add_shopping_cart(2, cart4);
    cout<<"Total Value of Customer 2"<<endl;
    std::cout << "customer 2 : " << cm.total_value(2) << std::endl;
    std::cout << "After sample data" << std::endl;
    cm.remove_item_from_cart(1, 1, 2);
    Shopping_cart cart = cm.retrive(1, 1);
    std::cout << "After Removing given item Displaying custmer 1 cart 1" << std::endl;
    cm.display_Shopping_Carts(1);
    cout<<"Total Value of customer 1"<<endl;
    std::cout << "customer 1 : " << cm.total_value(1) << std::endl;
    cm.Add_item_to_cart(1, 1, 4, "kokakola", 200, 3);
    Shopping_cart cartc = cm.retrive(1, 1);
    std::cout << "After Adding new item DIsplaying customer 1 cart 1" << std::endl;
    cm.display_Shopping_Carts(1);
    cout<<"Total Value of Customer 1"<<endl;
    std::cout << "customer 1 : " << cm.total_value(1) << std::endl;
    std::cout << "After Removing cart 1" << std::endl;
    cm.remove_shopping_cart(1, 1);
    std::cout << "customer 1 : " << cm.total_value(1) << std::endl;
    cm.display_Shopping_Carts(1);
    return 0;
}
