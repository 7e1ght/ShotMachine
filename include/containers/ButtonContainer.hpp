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

    void baseDraw() noexcept override;

    IInvoker* mInvoker;

    TextContainer mText;
    bool mIsAvailable;
    mutable uint64_t mTimer;
public: 
    void handleTouch(const supp::Point&) const override;

    TextContainer& getText() {return mText; }

    void setAvailable(bool available) noexcept;

    template<typename FunctionType>
    ButtonContainer(const String& text, FunctionType function, const supp::Point& position, const supp::Size& size, const supp::Color& color, IContainerBase* parent = nullptr);

    ~ButtonContainer() { delete mInvoker; }
};

template<typename FunctionType>
ButtonContainer::ButtonContainer(const String& text, 
            FunctionType function, 
            const supp::Point& position, 
            const supp::Size& size, 
            const supp::Color& color, 
            IContainerBase* parent
        ) 
    : IContainerBase(position, size, color, parent)
    , mText(text, supp::NO_POSITION, supp::DEFAULT_TEXT_COLOR, color, this)
    , mTimer(0)
    , mIsAvailable(true)
{
    IContainerBase::addContainer(&mText, IContainerBase::POSITION_CENTER);
    mInvoker = new InvokerRelease<FunctionType>(function);
}

#endif // BUTTON_CONTAINER_HPP