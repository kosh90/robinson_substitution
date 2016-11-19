#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fsubs.h"
//первый аргумент -- вывод миникс
//второй аргумент -- считать только первую матрицу

// найти и посчитать все уникальные "миноры" размера n x n в матрице m x m;

int main(int argc, char *argv[])
{
    std::cout << "первый аргумент -- вывод миникс" << std::endl <<
        "второй аргумент -- считать только первую матрицу" << std::endl;
    if (argc != 3)
    {
        std::cout << "bad argv" << std::endl;
        return 1;
    }

    bool onemx = atoi(argv[2]);
    typedef std::vector<int>   Row;
    typedef std::vector<Row>   Matrix;
    bool              output_trigger    = 1;
    bool              stop_after_one_mx = 0;
    int               n                 = 1;  // перебираем квадратики размера  n х 2 n
    long unsigned int m                 = 15; // в квадратище m x m
    long unsigned int num               = 0;
    int               uniq_count        = 0;  //счетчик уникальных
    int               uniq_num          = 0;  //номер уникального
    int               tmp               = 0;
    int               new_guys_count    = 0;
    int               k                 = 0;

    // сколько раз квадрат под данным номером встречается

    std::cout << "enter order of miniqs, please		-> ";
    std::cin >> n;

    std::cout << "enter order of supertile, please	-> ";
    std::cin >> m;
    std::cout << "========================" << std::endl;

    tmp = m;


    m = myPow(2, m + 5) - 1;


    // std::vector<int> minisquare;
    std::vector<int> how_many_u(4 * m * m);
    Matrix           all_minisquares(4 * m * m, Row(n * n));
    Matrix           uniq_minisquares(4 * m * m, Row(n * n));

    //---------------------------- body
    //подсчитать уникальные
    //посчитать семейства

    onemx = 1;
    while (k < 4)
    {
        // std::cout << "k =	"<< k << std::endl;
        std::cout << "------sq size = " << myPow(2, tmp + k) - 1 << std::endl;


        int total_elem = 0;
        int number     = 1;
        int count_sem  = 0;


        std::cout << std::endl;
        std::cout << "---------4 squares---------" << std::endl;
        // std::cout  << std::endl;

        num            = getMartices(all_minisquares, n, tmp + k, 0);
        new_guys_count = findNewUniqs(uniq_minisquares, all_minisquares, num, uniq_count);

        how_many_u.reserve(new_guys_count);
        for (int i = uniq_count; i < uniq_count + new_guys_count; i++)
        {
            how_many_u[i] = howManyUniqs(uniq_minisquares[i], all_minisquares, num);
            // std::cout << how_many_u[i] << std::endl;
        }

        total_elem = 0;
        number     = 1;
        count_sem  = 0;

        while (total_elem < new_guys_count)
        {
            count_sem = 0;
            for (int i = uniq_count; i < uniq_count + new_guys_count; i++)
            {
                if (how_many_u[i] == number)
                {
                    count_sem++;
                }
            }
            if (count_sem != 0)
            {
                std::cout << "семейств из " << number << " элементов --->		"<< count_sem << std::endl;
                total_elem += count_sem;
            }
            number++;
        }

        uniq_count += new_guys_count;
        std::cout << "-------> uniq_count = " << uniq_count << std::endl;
        // std::cout  << std::endl;



        k++;

        std::cout << "========================" << std::endl;
    }

    std::cout << "SDJFADKFJHASDLKFJHASDLKFJHASLKDJFHALK" << std::endl;


    std::cout << "n =	"<< n << std::endl;
    std::cout << "uniq_num =	"<< uniq_count << std::endl;
    write_miniqs_to_txt(uniq_minisquares, n, uniq_count);
    write_miniqs_to_js(uniq_minisquares, n, uniq_count);


    return 0;
}
