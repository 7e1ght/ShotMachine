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

	void Mojito() noexcept;
	void CubaLibre() noexcept;
	void Gilligan() noexcept;
	void RumOrangeJuice() noexcept;
	void PinaСolada() noexcept;
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

inline void Barman::CubaLibre() noexcept
{
  Cocktail cocktail("Cuba libre");

  cocktail.addStep(100, Liquid::RUM);
  cocktail.addStep(50, Liquid::COLA);

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
  Cocktail cocktail("RumOrangeJuice");

  cocktail.addStep(50, Liquid::RUM);
  cocktail.addStep(150, Liquid::ORANGE_JUICE);

  mShotMap.push_back(cocktail);
}

inline void Barman::PinaСolada() noexcept
{
  Cocktail cocktail("PinaСolada");
  
  cocktail.addStep(50, Liquid::RUM);
  cocktail.addStep(50, Liquid::PINEAPPLE_JUICE);
  cocktail.addStep(50, Liquid::SYRUP_COCONUT);

  mShotMap.push_back(cocktail);
}

inline void Barman::ElPresident() noexcept
{
  Cocktail cocktail("ElPresident");

  cocktail.addStep(50, Liquid::RUM);
  cocktail.addStep(50, Liquid::MARTINI);
  cocktail.addStep(50, Liquid::SPRITE);

  mShotMap.push_back(cocktail);
}

inline void Barman::Daiquiri() noexcept
{
  Cocktail cocktail("Вaiquiri");

  cocktail.addStep(60, Liquid::RUM);
  cocktail.addStep(40, Liquid::SPRITE);

  mShotMap.push_back(cocktail);
}

inline void Barman::Knickerbocker() noexcept
{
  Cocktail cocktail("Knickerbocker");

  cocktail.addStep(50, Liquid::RUM);
  cocktail.addStep(50, Liquid::LIQUOR_CHERRY);
  cocktail.addStep(50, Liquid::SPRITE);
  cocktail.addStep(50, Liquid::ORANGE_JUICE);

  mShotMap.push_back(cocktail);
}

inline void Barman::initShotMap() noexcept
{
	Mojito();
	CubaLibre();
	Gilligan();
	RumOrangeJuice();
	PinaСolada();
	ElPresident();
	Daiquiri();
	Knickerbocker();
}

inline void Barman::initBottleShelf() noexcept
{
	mBottleShelf.push_back(Bottle(14, Liquid::COLA));
	mBottleShelf.push_back(Bottle(15, Liquid::ORANGE_JUICE));
	mBottleShelf.push_back(Bottle(16, Liquid::SYRUP_COCONUT));
	mBottleShelf.push_back(Bottle(17, Liquid::PINEAPPLE_JUICE));
	mBottleShelf.push_back(Bottle(18, Liquid::RUM));
	mBottleShelf.push_back(Bottle(19, Liquid::MARTINI));
	mBottleShelf.push_back(Bottle(20, Liquid::LIQUOR_CHERRY));
	mBottleShelf.push_back(Bottle(21, Liquid::SPRITE));
}

inline const Cocktail& Barman::getCocktailByIndex(const CocktailIdx index) const noexcept
{
	return mShotMap[index];
}

#endif // BARMAN_HPP