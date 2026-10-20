#include <iostream>
#include <math.h>

#include <config.h>
#include <data_step.cpp>



void algoritm_Metropolis()
{

	for (int step = 0; step < static_configuration; ++step)
	{
		

		for (int mcs = 0; mcs < maxMCS; ++mcs)
				{
					for (int n = 0; n < L*L*N; ++n)
					{
						i = rund(1,L);
						j = rund(1,L);
						spin = E1;
						E2 = latins[i][j];
						if (E1>E2)
						{
							spin = latins[i][j];
						}else{
							const double Z = exp(-(E2-E1)/T); 
							rund = rund(0,1);
							if (Z < rund)
							{
							spin = latins[i][j];	
							}
						}
					}

					magmom(spin);

				}	




	}

}

int main()
{

	std::vector<int> i;
	std::vector<vector<int>> j; 



	return 0;
}

