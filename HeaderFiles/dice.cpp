// #include<iostream>
// #include "HUMania.hpp"
// #include <vector>

// using namespace std;

// // int x;
// // int y;

// vector<Unit> blue; //blue vector is initialized
// vector<Unit> yellow;//bees vector is initialized
// vector<Unit>red;//butterflies vector is initialized
// vector<Unit> green;//butterflies vector is initialized


// int blue_state=0;//initial state of pigeon is set to zero

// int red_state=0;//initial state of bee is set to zero

// int green_state=0;////initial state of butterfly is set to zero
// int yellow_state=0;////initial state of butterfly is set to zero

// void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets){
//     // TODO: Write code to iterate over all the vectors and draw objects here: 
    
//    //Loop over all the blue in the pigeon vector(blue.size()-->no of blue in the vector)
//     for (int i=0;i<blue.size();i++) 
//     {
//        //reference to the pigeon object from the blue vector
//        Unit& blues = blue[i];
//        //Draw the pigeon
//        SDL_RenderCopy(gRenderer, assets, &blues.srcRect, &blues.moverRect);
//        // moves the pigeon two pixel towards right
//        pigeon.moverRect.x+=2;// moves the pigeon two pixel towards right
       
//        if(blue_state==0){//initial state
//         blue[i].srcRect.x=12;
//         blue[i].srcRect.y=1234;
//         blue[i].srcRect.w=180;
//         blue[i].srcRect.h=158;
//         blue_state+=1;
//        }
//        else if(blue_state==1){//flying up state of the pigeon
//             blue[i].srcRect.x=17;
//             blue[i].srcRect.y=1436;
//             blue[i].srcRect.w=179;
//             blue[i].srcRect.h=159;
//             blue_state+=1;
//        }
//        else if{//flying down state of the pigeon(blue_state=2)
//             blue[i].srcRect.x=13;
//             blue[i].srcRect.y=1641;
//             blue[i].srcRect.w=180;
//             blue[i].srcRect.h=159;
//             blue_state+=1;//after this state of the pigeon again becomes static and then the loop goes on
//        }
              
//        else if(blue_state==0){//initial state
//         blue[i].srcRect.x=12;
//         blue[i].srcRect.y=1234;
//         blue[i].srcRect.w=180;
//         blue[i].srcRect.h=158;
//         blue_state+=1;
//        }
//        else if(blue_state==1){//flying up state of the pigeon
//             blue[i].srcRect.x=17;
//             blue[i].srcRect.y=1436;
//             blue[i].srcRect.w=179;
//             blue[i].srcRect.h=159;
//             blue_state+=1;
//        }
//        else {//flying down state of the pigeon(blue_state=2)
//             blue[i].srcRect.x=13;
//             blue[i].srcRect.y=1641;
//             blue[i].srcRect.w=180;
//             blue[i].srcRect.h=159;
//             blue_state+=1;//after this state of the pigeon again becomes static and then the loop goes on
//        }
//        //if pigeon goes to the right hand side it should again appear from the left side
//        if(pigeon.moverRect.x>=1000){//screenwidth=1000 from game.hpp
//         pigeon.moverRect.x = 0;
//        }
//     }

//     for (int i=0;i<butterflies.size();i++) {
//        //reference to the pigeon object from the blue vector
//        Unit& butterfly = butterflies[i];
//        //Draw the butterfly
//        SDL_RenderCopy(gRenderer, assets, &butterfly.srcRect, &butterfly.moverRect);
//        // moves the butterfly two pixel towards right
//        butterfly.moverRect.x+=2;
//         if(butterfly_state==0){//initial state
//             butterflies[i].srcRect.x=257;
//             butterflies[i].srcRect.y=24;
//             butterflies[i].srcRect.w=173;
//             butterflies[i].srcRect.h=134;
//             butterfly_state+=1;
//        }
//        else if(butterfly_state==1){//flying down state of the butterfly
//             butterflies[i].srcRect.x=257;
//             butterflies[i].srcRect.y=182;
//             butterflies[i].srcRect.w=192;
//             butterflies[i].srcRect.h=214;
//             butterfly_state+=1;
//        }
//        else {//flying up state of the butterfly(butterfly_state=2)
//             butterflies[i].srcRect.x=248;
//             butterflies[i].srcRect.y=432;
//             butterflies[i].srcRect.w=248;
//             butterflies[i].srcRect.h=179;
//             butterfly_state=0;//after this state of the butterfly again becomes static and then the loop goes on
//        }
//        //if butterfly goes to the right hand side it should again appear from the left side
//        if(butterfly.moverRect.x>1000){//screenwidth=1000 from game.hpp
//         butterfly.moverRect.x = 0;
//        }
//     }

//     for (int i=0;i<bees.size();i++) {
//        //reference to the bee object from the blue vector
//        Unit& bee = bees[i];
//        //Draw the bee
//        SDL_RenderCopy(gRenderer, assets, &bee.srcRect, &bee.moverRect);
//        // moves the bee two pixel towards right
//        bee.moverRect.x+=2;
//         if(bee_state==0){//initial state
//             bees[i].srcRect.x=527;
//             bees[i].srcRect.y=138;
//             bees[i].srcRect.w=194;
//             bees[i].srcRect.h=115;
//             bee_state+=1;
//        }
//        else if(bee_state==1){//intermediate flying state of bee
//             bees[i].srcRect.x=527;
//             bees[i].srcRect.y=254;
//             bees[i].srcRect.w=194;
//             bees[i].srcRect.h=115;
//             bee_state+=1;
//        }
//        else {//flying up state of the butterfly(butterfly_state=2)
//             bees[i].srcRect.x=540;
//             bees[i].srcRect.y=370;
//             bees[i].srcRect.w=193;
//             bees[i].srcRect.h=115;
//             bee_state=0;//after this state of the bee again becomes static and then the loop goes on
//        }
//        //if bee goes to the right hand side it should again appear from the left side
//        if(bee.moverRect.x>1000){//screenwidth=1000 from game.hpp
//         bee.moverRect.x = 0;
//        }
//     }
// }

// void createObject(int x, int y){

//     // TODO: create an object randomly, and push it into corresponding vector
//     std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
//     int random_object= rand() % 3;

//     if (random_object== 0) {//a pigeon is pushed into the vector
//         blue.push_back({{7,88,155,103},{x, y, 50, 50}});
//     } 
//     else if (random_object == 1) {//a butterfly is pushed into the vector
//         butterflies.push_back({{257,24,173,134}, {x, y, 50, 50}});
//     } 
//     else if (random_object == 2) {// a bee is pushed into the vector
//         bees.push_back({{527,138,194,115}, {x, y, 50, 50}});
//     }
// }



