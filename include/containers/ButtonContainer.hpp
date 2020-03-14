#ifndef BUTTON_CONTAINER_HPP
#define BUTTON_CONTAINER_HPP

#include "containers/IContainerBase.hpp"
#include "containers/TextContainer.hpp"
#include "support/support.hpp"

class ButtonContainer 
    : public IContainerBase
{
private:
    struct IInvoker
    {
        virtual void invoke() = 0;
        virtual ~IInvoker() {}
    };

    template<typename FunctionType>
    class InvokerRelease
        : public IInvoker
    {
    private:
        FunctionType mFunction;
        void invoke() { mFunction(); }
    public:
        InvokerRelease(FunctionType function) : mFunction(function) {}
    };

    IInvoker* mInvoker;

    TextContainer mText;
public: 
    void draw() const override;
    void handleTouch(const supp::Point&) const override { mInvoker->invoke(); }

    template<typename FunctionType>
    ButtonContainer(const String& text, FunctionType function, const supp::Point& position, const supp::Size& size, const supp::Color& color);

    ~ButtonContainer() { delete mInvoker; }
};

template<typename FunctionType>
ButtonContainer::ButtonContainer(const String& text, FunctionType function, const supp::Point& position, const supp::Size& size, const supp::Color& color) 
    : IContainerBase(position, size, color)
    , mText(text, supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, color) 
{
    IContainerBase::addContainer(&mText, IContainerBase::POSITION_CENTER);
    mInvoker = new InvokerRelease<FunctionType>(function);
}

#endif // BUTTON_CONTAINER_HPP