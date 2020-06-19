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

	bool isNextGlassFound() noexcept;

	int8_t NO_VALID_COCKTAIL_INDEX = -1;

	supp::Vector<CocktailIdx> mOrder;

	void makeCocktail(const CocktailIdx index) const noexcept;

	supp::Vector<Bottle> mBottleShelf;
	supp::Vector<Cocktail> mShotMap;

	int8_t mLastGivenGlassIndex; 

	void initShotMap() noexcept;
	void initBottleShelf() noexcept;

	Barman();

	void Mojito() noexcept;
	void Rum() noexcept;
	void Gilligan() noexcept;
	void RumOrangeJuice() noexcept;
	void PinaColada() noexcept;
	void ElPresident() noexcept;
	void Daiquiri() noexcept;
	void Knickerbocker() noexcept;
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

inline void Barman::Mojito() noexcept
{
	Cocktail cocktail("Mojito");

	cocktail.addStep(100, Liquid::RUM);
	cocktail.addStep(50, Liquid::SPRITE);

	mShotMap.push_back(cocktail);
}

inline void Barman::Rum() noexcept
{
  Cocktail cocktail("Rum");

  cocktail.addStep(100, Liquid::RUM);
//   cocktail.addStep(50, Liquid::COLA);

  mShotMap.push_back(cocktail);
}

inline void Barman::Gilligan() noexcept
{
  Cocktail cocktail("Gilligan");

  cocktail.addStep(60, Liquid::RUM);
  cocktail.addStep(30, Liquid::PINEAPPLE_JUICE);
  cocktail.addStep(30, Liquid::SPRITE);

  mShotMap.push_back(cocktail);
}

inline void Barman::RumOrangeJuice() noexcept
{
  Cocktail cocktail("Rum Orange Juice");

  cocktail.addStep(50, Liquid::RUM);
  cocktail.addStep(150, Liquid::ORANGE_JUICE);

  mShotMap.push_back(cocktail);
}

inline void Barman::PinaColada() noexcept
{
  Cocktail cocktail("Pina Colada");
  
  cocktail.addStep(50, Liquid::RUM);
  cocktail.addStep(50, Liquid::PINEAPPLE_JUICE);
  cocktail.addStep(50, Liquid::SYRUP_COCONUT);

  mShotMap.push_back(cocktail);
}

inline void Barman::ElPresident() noexcept
{
  Cocktail cocktail("El President");

  cocktail.addStep(50, Liquid::RUM);
  cocktail.addStep(50, Liquid::MARTINI);
  cocktail.addStep(50, Liquid::SPRITE);

  mShotMap.push_back(cocktail);
}

inline void Barman::Daiquiri() noexcept
{
  Cocktail cocktail("Daiquiri");

  cocktail.addStep(60, Liquid::RUM);
  cocktail.addStep(40, Liquid::SPRITE);

  mShotMap.push_back(cocktail);
}

inline void Barman::Knickerbocker() noexcept
{
  Cocktail cocktail("Knickerbocker");

  cocktail.addStep(50, Liquid::RUM);
//   cocktail.addStep(50, Liquid::LIQUOR_CHERRY);
  cocktail.addStep(50, Liquid::SPRITE);
  cocktail.addStep(50, Liquid::ORANGE_JUICE);

  mShotMap.push_back(cocktail);
}

inline void Barman::initShotMap() noexcept
{
	Mojito();
	Rum();
	Gilligan();
	RumOrangeJuice();
	PinaColada();
	ElPresident();
	Daiquiri();
	Knickerbocker();
}

inline void Barman::initBottleShelf() noexcept
{
	mBottleShelf.push_back(Bottle(14, Liquid::RUM));
	mBottleShelf.push_back(Bottle(15, Liquid::MARTINI));
	mBottleShelf.push_back(Bottle(16, Liquid::SYRUP_COCONUT));
	// mBottleShelf.push_back(Bottle(17, Liquid::LIQUOR_CHERRY));
	// mBottleShelf.push_back(Bottle(18, Liquid::COLA));
	mBottleShelf.push_back(Bottle(18, Liquid::SPRITE));
	mBottleShelf.push_back(Bottle(20, Liquid::PINEAPPLE_JUICE));
	mBottleShelf.push_back(Bottle(21, Liquid::ORANGE_JUICE));
}

inline const Cocktail& Barman::getCocktailByIndex(const CocktailIdx index) const noexcept
{
	return mShotMap[index];
}

#endif // BARMAN_HPP