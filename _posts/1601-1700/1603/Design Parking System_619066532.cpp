class ParkingSystem {
public:
    vector<int> cars;
    ParkingSystem(int big, int medium, int small) {
        cars = vector<int>(3, 0);
        cars[0] = big;
        cars[1] = medium;
        cars[2] = small;
    }
    bool addCar(int carType) {
        if(cars[carType-1]!=0){
            cars[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
