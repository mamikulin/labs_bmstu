#include <iostream>

void timeday(int hour_int);
void minutef(int hour_int);
void hourf(int hour_int);

int main(){
    int hour_int, minute_int;
    for (int i = 0; i < 100; i++){
        
        std::cout << "time:";
        std::cin >> hour_int >> minute_int;;
        
        if ((hour_int < 24 && hour_int >= 0) && (minute_int <= 60 && minute_int >= 0)){
            if (hour_int == 0 && minute_int == 0){
                std::cout << "полночь" << std::endl;
            }
            else if(hour_int == 12 && minute_int == 0){
                std::cout << "полдень" << std::endl;
            }
            else{
                
                int hour_int_old = hour_int;
                if (hour_int > 12){
                    hour_int = hour_int - 12;
                }
                
                std::cout << hour_int;
                hourf(hour_int);
                
                if (minute_int == 0){
                    timeday(hour_int_old);
                    std::cout << " ровно " << std::endl;
                }
                else{
                    std::cout  << minute_int;
                    minutef(minute_int);
                    timeday(hour_int_old);
                    std::cout << std::endl;
                }
            }
        }
        else{
            std::cout << "введены недопустимые данные" << std::endl;
        }
    }
    return 0;
}

void timeday(int hour_int){
    if (hour_int >= 5 && hour_int < 12){
        std::cout<<"утра";
    }
    else if (hour_int >= 12 && hour_int < 18){
        std::cout<<"дня";
    }
    else if (hour_int >= 18 && hour_int < 23){
        std::cout<<"вечера";
    }
    else{
        std::cout<<"ночи";
    }
}

void minutef(int minute_int){
    std::string m;
    if (minute_int % 10 <= 4 && minute_int % 10 > 1  && not(minute_int >= 10 && minute_int < 15)) {
        std::cout<<" минуты ";
    }
    else if (minute_int == 1) {
        std::cout<<" минута ";
    }
    else{
        std::cout<<" минут ";
    }
}

void hourf(int hour_int){
    std::string h;
    if (hour_int >= 5 || hour_int == 0){
        std::cout<<" часов ";
    }
    else if (hour_int == 1){
        std::cout<<" час ";
    }
    else if (hour_int == 2 || hour_int == 3 || hour_int == 4){
        std::cout<<" часа ";
    }
}
