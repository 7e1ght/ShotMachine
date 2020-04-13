// #ifndef MAIN_SCENE_HPP
// #define MAIN_SCENE_HPP

// #include "IScene.hpp"

// #include "containers/EmptyContainer.hpp"
// #include "containers/TripleContainer.hpp"
// #include "containers/ListContainer.hpp"
// #include "containers/ButtonContainer.hpp"

// class MainScene
// : public IScene
// {
// public:
//     MainScene();
// private:
//     void initElements() noexcept;
//     void addElements() noexcept;

//     TripleContainer* upperBar;
//     TripleContainer* lowerBar;

//     EmptyContainer* contentLayout;

//     ListContainer* cocktailContent;

//     EmptyContainer* buttonLayout;
 
//     ButtonContainer* createTemplate;
//     ButtonContainer* toQueu;
//     ButtonContainer* coock;

//     ~MainScene()
//     {
//         delete upperBar;
//         delete lowerBar;
//         delete contentLayout;
//         delete cocktailContent;
//         delete buttonLayout;
//         delete createTemplate;
//         delete toQueu;
//         delete coock;
//     }
// };

// #endif // MAIN_SCENE_HPP