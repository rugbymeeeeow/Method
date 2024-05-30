#include <iostream>
#include <map>

using namespace std;


struct ProductParams {
    double width;
    double height;
};


map<int, double> productCoefficients = {
    {1, 0.5},
    {2, 1.0},
    {3, 1.5},
};


map<int, double> materialWastage = {
    {1, 0.05},
    {2, 0.10},
    {3, 0.15},
};

int calculateMaterialAmount(int productType, int materialType, int productCount, double productParam1, double productParam2) {

    if (productCoefficients.find(productType) == productCoefficients.end() || materialWastage.find(materialType) == materialWastage.end()) {
        return -1;
    }

    double materialPerProduct = productCoefficients[productType] * productParam1 * productParam2;

    double materialWithWastage = materialPerProduct * (1 + materialWastage[materialType]);

    int totalMaterial = materialWithWastage * productCount;

    return totalMaterial;
}

int main() {
    int productType, materialType, productCount;
    double productParam1, productParam2;
    cout << "Enter product type ID: ";
    cin >> productType;
    cout << "Enter material type ID: ";
    cin >> materialType;
    cout << "Enter the quantity of products: ";
    cin >> productCount;
    cout << "Enter first parametr: ";
    cin >> productParam1;
    cout << "Enter second parametr: ";
    cin >> productParam2;

    int materialAmount = calculateMaterialAmount(productType, materialType, productCount, productParam1, productParam2);

    if (materialAmount == -1) {
        cout << "Error" << endl;
    }
    else {
        cout << "Amount of material you need: " << materialAmount << endl;
    }

    return 0;
}