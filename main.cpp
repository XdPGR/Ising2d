#include <iostream>
#include <math.h>
#include <vector>
#include <random>
#include "config.h"
#include "spin.h"
//#include <data_work.cpp>
//
      
//
/*			Конфиг
const int  l = 16;
const double t = 4.5;
const int j = -1;
const int maxmcs = 10000;
const int static_configuration = 100;
*/

inline spin get_random_spin()
{
	spin rundom_spin;

	rundom_spin.z = -1;

	return rundom_spin;
}



// void full_random(std::vector<std::vector<int>>& lattice)
// {
// 	std::random_device rd;
// 	std::mt19937 gen(rd());
// 	std::bernoulli_distribution coin (0.5);

// 	for (int i = 0; i < (int)lattice.size(); i++)
// 	{
// 		for (int j = 0; j < (int)lattice[i].size(); j++)
// 		{
// 			lattice[i][j] = +1;
// 		}
// 	}
// }


double get_energy_two_spin(spin const sp_1, spin const sp_2)
{


    return (-J*(sp_1.z * sp_2.z));
}

double get_energy_neighbors(spin const *const *const sp, int const& i, int const& j) noexcept //Сделал граничные условия(периодические)
{
    // lattice[i][j] -> sp[i][j];

	//int L = (int)sp.size();
	double energy = 0;
	// int up     = lattice[(i - 1 + L) % L][j];
	// int down   = lattice[(i + 1) % L][j];
	// int left   = lattice[i][(j - 1 + L) % L];
	// int right  = lattice[i][(j + 1) % L];
	energy += get_energy_two_spin(sp[i][j], sp[(i - 1 + L) % L][j]);
	energy += get_energy_two_spin(sp[i][j], sp[(i + 1) % L][j]);
	energy += get_energy_two_spin(sp[i][j], sp[i][(j - 1 + L) % L]);
	energy += get_energy_two_spin(sp[i][j], sp[i][(j + 1) % L]);
	return energy;
}




void algoritm_Metropolis()
  {

	  for (int step = 0; step < static_configuration; ++step)
	  {

//std::vector<std::vector<int>> lattice(L, std::vector<int>(L, 0));

spin** lattice = new spin* [L];
	for (int i = 0; i < L; i++)
	{
		lattice[i] = new spin [L];
	}



//full_random(lattice);

		  for (int mcs = 0; mcs < maxMCS; ++mcs)
		  {


			  for (int n = 0; n < L*L; ++n)
			  {
					 int i = 5;
					 int j = 7;

					  spin selected_spin = lattice[i][j];
					 const double E1 = get_energy_neighbors(lattice, i, j);

					 lattice[i][j] = get_random_spin();
					 const double E2 = get_energy_neighbors(lattice, i, j);

					  if (E1>E2)
					  {
					  selected_spin = lattice[i][j];
					  }
					  else
					  {
						  const double Z = exp(-(E2-E1)/T);
						  int rund = -1;

					  if (Z < rund)
					  {
					  	lattice[i][j] = selected_spin;
					  }
					  }
			  }

		  //Data_work::updata_output_data();

		  }

	  }

  }

// void print (std::vector<std::vector<int>> const lattice)
// {
// 	for(int i = 0; i < L; i++)
// 	{
// 		for (int j = 0; j < L; j++)
// 		{
// 			std::cout << lattice[i][j] << ' ';
// 		}
// 		std::cout << '\n';
// 	}
// }
int main()
{

	              /*инициализация спинов*/
	//fill_random(lattice);
	//print(lattice);

	//Тест граничных условий
	// for (int i = 0; i < L; ++i)
	// 	for (int j = 0; j < L; ++j)
	// 		lattice[i][j] = +1;

	// std::cout << get_energy_neighbors(lattice, 0, 0) << '\n';
	// std::cout << get_energy_neighbors(lattice, 0, 5) << '\n';
	// std::cout << get_energy_neighbors(lattice, 8, 8) << '\n';

	return 0;
}

