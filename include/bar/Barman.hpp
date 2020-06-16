#ifndef BARMAN_HPP
#define BARMAN_HPP

#include "support/support.hpp"
#include "support/Vector.hpp"

#include "bar/Glass.hpp"
#include "bar/Cocktail.hpp"

class Barman
{
public:
	using CocktailIdx = int8_t;

	void executeOrder() noexcept;
	void addOrder(const CocktailIdx cocktail) noexcept;

	bool isOrderContains(const CocktailIdx cocktail) const noexcept;

	const Cocktail& getCocktailByIndex(const CocktailIdx index) const noexcept;
	const Bottle& getBottleByLiquid(const Liquid::Type liquid) const noexcept;

	static Barman& getInstance() noexcept;

	const supp::Vector<Bottle>& getBottleShelf() const noexcept;
	const supp::Vector<Glass>& getGlasses() const noexcept;
	const supp::Vector<Cocktail>& getShotMap() const noexcept;

	const bool isLiquidEnough( const Liquid::Type liquid, const uint16_t value ) const noexcept;

	Glass& getGlass() noexcept;

private:
	Glass mGlass;

	int8_t NO_VALID_COCKTAIL_INDEX = -1;

	supp::Vector<CocktailIdx> mOrder;

	void makeCocktail(const CocktailIdx index) const noexcept;

	supp::Vector<Bottle> mBottleShelf;
	supp::Vector<Cocktail> mShotMap;

	int8_t mLastGivenGlassIndex; 

	void initShotMap() noexcept;
	void initBottleShelf() noexcept;

	Barman();

	void Screwdriver() noexcept;
	void Jaguar() noexcept;
	void Rollshot() noexcept;
	void MartiniWithVodka() noexcept;
	void SunnyLagoon() noexcept;
	void BlueLagoon() noexcept;
};

inline const supp::Vector<Bottle>& Barman::getBottleShelf() const noexcept
{
	return mBottleShelf;
}

inline const supp::Vector<Cocktail>& Barman::getShotMap() const noexcept
{
	return mShotMap;
}

inline Glass& Barman::getGlass() noexcept
{
	return mGlass;
}

inline void Barman::Screwdriver() noexcept
{
	Cocktail cocktail("Screwdriver");

	cocktail.addStep(50, Liquid::VODKA);
	cocktail.addStep(150, Liquid::ORANGE_JUICE);

	mShotMap.push_back(cocktail);
}

inline void Barman::Jaguar() noexcept
{
  Cocktail cocktail("Jaguar");

  cocktail.addStep(50, Liquid::VODKA);
  cocktail.addStep(50, Liquid::LIQUOR_COCONUT);
  cocktail.addStep(150, Liquid::SPRITE);

  mShotMap.push_back(cocktail);
}

inline void Barman::Rollshot() noexcept
{
  Cocktail cocktail("Roll Shot");

  cocktail.addStep(20, Liquid::VODKA);
  cocktail.addStep(20, Liquid::SYRUP_RASPBERRY);

  mShotMap.push_back(cocktail);
}

inline void Barman::MartiniWithVodka() noexcept
{
  Cocktail cocktail("Martini-Vodka");

  cocktail.addStep(70, Liquid::VODKA);
  cocktail.addStep(20, Liquid::MARTINI);

  mShotMap.push_back(cocktail);
}

inline void Barman::SunnyLagoon() noexcept
{
  Cocktail cocktail("Sunny lagoon");
  
  cocktail.addStep(25, Liquid::LEMON_JUICE);
  cocktail.addStep(100, Liquid::SPRITE);
  cocktail.addStep(50, Liquid::VODKA);

  mShotMap.push_back(cocktail);
}

inline void Barman::BlueLagoon() noexcept
{
  Cocktail cocktail("Blue lagoon");

  cocktail.addStep(25, Liquid::LEMON_JUICE);
  cocktail.addStep(100, Liquid::SPRITE);
  cocktail.addStep(30, Liquid::VODKA);
  cocktail.addStep(30, Liquid::CURACAO);

  mShotMap.push_back(cocktail);
}

inline void Barman::initShotMap() noexcept
{
	Screwdriver();
	Jaguar();
	Rollshot();
	MartiniWithVodka();
	SunnyLagoon();
	BlueLagoon();
}

inline void Barman::initBottleShelf() noexcept
{
	mBottleShelf.push_back(Bottle(14, Liquid::VODKA));
	mBottleShelf.push_back(Bottle(15, Liquid::ORANGE_JUICE));
	mBottleShelf.push_back(Bottle(16, Liquid::LIQUOR_COCONUT));
	mBottleShelf.push_back(Bottle(18, Liquid::SYRUP_RASPBERRY));
	mBottleShelf.push_back(Bottle(19, Liquid::MARTINI));
	mBottleShelf.push_back(Bottle(20, Liquid::LEMON_JUICE));
	mBottleShelf.push_back(Bottle(21, Liquid::SPRITE));
	mBottleShelf.push_back(Bottle(21, Liquid::CURACAO));
}

inline const Cocktail& Barman::getCocktailByIndex(const CocktailIdx index) const noexcept
{
	return mShotMap[index];
}

#endif // BARMAN_HPP