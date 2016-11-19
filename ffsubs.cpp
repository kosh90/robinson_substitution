#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "fsubs.h"


int find_next_pos(std::vector< std::vector<int> > &out_matrix, int *pos)
{
    for (int i = 0; i < out_matrix.size(); i++)
    {
        for (int j = 0; j < out_matrix.size(); j++)
        {
            if (out_matrix[i][j] == -1)
            {
                pos[0] = i;
                pos[1] = j;
                return 0;
            }
        }
    }
    return -1;
}

void substitute(int i, int j, std::vector< std::vector<int> > &in_matrix, std::vector< std::vector<int> > &out_matrix, int *pos)
{
    // std::cout << "sub " << pos[0] << "," << pos[1] << std::endl;
    //pos[0] -- строка
    //pos[1] -- столбец

    if (in_matrix [i] [j] == 0)  //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 0;
        out_matrix[pos[0] + 0][pos[1] + 1] = 16;
        out_matrix[pos[0] + 0][pos[1] + 2] = 3;
        out_matrix[pos[0] + 1][pos[1] + 0] = 17;
        out_matrix[pos[0] + 1][pos[1] + 1] = 4;
        out_matrix[pos[0] + 1][pos[1] + 2] = 31;
        out_matrix[pos[0] + 2][pos[1] + 0] = 1;
        out_matrix[pos[0] + 2][pos[1] + 1] = 22;
        out_matrix[pos[0] + 2][pos[1] + 2] = 2;

        pos[1] = pos[1] + 3;
    }
    if (in_matrix [i] [j] == 1)            //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 0;
        out_matrix[pos[0] + 0][pos[1] + 1] = 28;
        out_matrix[pos[0] + 0][pos[1] + 2] = 3;
        out_matrix[pos[0] + 1][pos[1] + 0] = 17;
        out_matrix[pos[0] + 1][pos[1] + 1] = 5;
        out_matrix[pos[0] + 1][pos[1] + 2] = 23;
        out_matrix[pos[0] + 2][pos[1] + 0] = 1;
        out_matrix[pos[0] + 2][pos[1] + 1] = 18;
        out_matrix[pos[0] + 2][pos[1] + 2] = 2;
        pos[1]                             = pos[1] + 3;
    }
    if (in_matrix [i] [j] == 2)            //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 0;
        out_matrix[pos[0] + 0][pos[1] + 1] = 20;
        out_matrix[pos[0] + 0][pos[1] + 2] = 3;
        out_matrix[pos[0] + 1][pos[1] + 0] = 29;
        out_matrix[pos[0] + 1][pos[1] + 1] = 6;
        out_matrix[pos[0] + 1][pos[1] + 2] = 19;
        out_matrix[pos[0] + 2][pos[1] + 0] = 1;
        out_matrix[pos[0] + 2][pos[1] + 1] = 18;
        out_matrix[pos[0] + 2][pos[1] + 2] = 2;
        pos[1]                             = pos[1] + 3;
    }
    if (in_matrix [i] [j] == 3)            //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 0;
        out_matrix[pos[0] + 0][pos[1] + 1] = 16;
        out_matrix[pos[0] + 0][pos[1] + 2] = 3;
        out_matrix[pos[0] + 1][pos[1] + 0] = 21;
        out_matrix[pos[0] + 1][pos[1] + 1] = 7;
        out_matrix[pos[0] + 1][pos[1] + 2] = 19;
        out_matrix[pos[0] + 2][pos[1] + 0] = 1;
        out_matrix[pos[0] + 2][pos[1] + 1] = 30;
        out_matrix[pos[0] + 2][pos[1] + 2] = 2;
        pos[1]                             = pos[1] + 3;
    }
    if (in_matrix[i][j] == 4)            //ok
    {
        out_matrix[pos[0]][pos[1]] = 4;
        pos[1]                     = pos[1] + 1;
    }
    if (in_matrix[i][j] == 5)            //ok
    {
        out_matrix[pos[0]][pos[1]] = 5;
        pos[1]                     = pos[1] + 1;
    }
    if (in_matrix[i][j] == 6)            //ok
    {
        out_matrix[pos[0]][pos[1]] = 6;
        pos[1]                     = pos[1] + 1;
    }
    if (in_matrix[i][j] == 7)            //ok
    {
        out_matrix[pos[0]][pos[1]] = 7;
        pos[1]                     = pos[1] + 1;
    }
    if (in_matrix[i][j] == 8)//ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 8;
        out_matrix[pos[0] + 1][pos[1] + 0] = 8;
        pos[1]                             = pos[1] + 1;
    }
    if (in_matrix[i][j] == 9)//ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 9;
        out_matrix[pos[0] + 0][pos[1] + 1] = 9;
        pos[1]                             = pos[1] + 2;
    }
    if (in_matrix[i][j] == 10)//ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 10;
        out_matrix[pos[0] + 1][pos[1] + 0] = 10;
        pos[1]                             = pos[1] + 1;
    }
    if (in_matrix[i][j] == 11)//ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 11;
        out_matrix[pos[0] + 0][pos[1] + 1] = 11;
        pos[1]                             = pos[1] + 2;
    }
    if (in_matrix[i][j] == 12) //ok
    {
        out_matrix[pos[0] + 0][pos[1]] = 12;
        out_matrix[pos[0] + 1][pos[1]] = 12;
        pos[1]                         = pos[1] + 1;
    }
    if (in_matrix[i][j] == 13) //ok
    {
        out_matrix[pos[0]][pos[1] + 0] = 13;
        out_matrix[pos[0]][pos[1] + 1] = 13;
        pos[1]                         = pos[1] + 2;
    }
    if (in_matrix[i][j] == 14) //ok
    {
        out_matrix[pos[0] + 0][pos[1]] = 14;
        out_matrix[pos[0] + 1][pos[1]] = 14;
        pos[1]                         = pos[1] + 1;
    }
    if (in_matrix[i][j] == 15) //ok
    {
        out_matrix[pos[0]][pos[1] + 0] = 15;
        out_matrix[pos[0]][pos[1] + 1] = 15;
        pos[1]                         = pos[1] + 2;
    }
    if (in_matrix [i] [j] == 16) //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 8;
        out_matrix[pos[0] + 1][pos[1] + 0] = 16;
        out_matrix[pos[0] + 2][pos[1] + 0] = 8;
        pos[1]                             = pos[1] + 1;
    }
    if (in_matrix[i][j] == 17)            //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 9;
        out_matrix[pos[0] + 0][pos[1] + 1] = 17;
        out_matrix[pos[0] + 0][pos[1] + 2] = 9;
        pos[1]                             = pos[1] + 3;
    }
    if (in_matrix[i][j] == 18)            //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 10;
        out_matrix[pos[0] + 1][pos[1] + 0] = 18;
        out_matrix[pos[0] + 2][pos[1] + 0] = 10;
        pos[1]                             = pos[1] + 1;
    }
    if (in_matrix[i][j] == 19)            //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 11;
        out_matrix[pos[0] + 0][pos[1] + 1] = 19;
        out_matrix[pos[0] + 0][pos[1] + 2] = 11;
        pos[1]                             = pos[1] + 3;
    }
    if (in_matrix[i][j] == 20)            //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 12;
        out_matrix[pos[0] + 1][pos[1] + 0] = 20;
        out_matrix[pos[0] + 2][pos[1] + 0] = 12;
        pos[1]                             = pos[1] + 1;
    }
    if (in_matrix[i][j] == 21)            //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 13;
        out_matrix[pos[0] + 0][pos[1] + 1] = 21;
        out_matrix[pos[0] + 0][pos[1] + 2] = 13;
        pos[1]                             = pos[1] + 3;
    }
    if (in_matrix [i] [j] == 22)
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 14;
        out_matrix[pos[0] + 1][pos[1] + 0] = 22;
        out_matrix[pos[0] + 2][pos[1] + 0] = 14;
        pos[1]                             = pos[1] + 1;
    }
    if (in_matrix [i] [j] == 23)
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 15;
        out_matrix[pos[0] + 0][pos[1] + 1] = 23;
        out_matrix[pos[0] + 0][pos[1] + 2] = 15;
        pos[1]                             = pos[1] + 3;
    }
    if (in_matrix [i] [j] == 24)
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 24;
        out_matrix[pos[0] + 1][pos[1] + 0] = 24;
        pos[1]                             = pos[1] + 1;
    }
    if (in_matrix [i] [j] == 25)
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 25;
        out_matrix[pos[0] + 0][pos[1] + 1] = 25;
        pos[1]                             = pos[1] + 2;
    }

    if (in_matrix [i] [j] == 26)
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 26;
        out_matrix[pos[0] + 1][pos[1] + 0] = 26;
        pos[1]                             = pos[1] + 1;
    }

    if (in_matrix [i] [j] == 27)
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 27;
        out_matrix[pos[0] + 0][pos[1] + 1] = 27;
        pos[1]                             = pos[1] + 2;
    }
    if (in_matrix [i] [j] == 28) //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 24;
        out_matrix[pos[0] + 1][pos[1] + 0] = 28;
        out_matrix[pos[0] + 2][pos[1] + 0] = 24;
        pos[1]                             = pos[1] + 1;
    }
    if (in_matrix [i] [j] == 29) //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 25;
        out_matrix[pos[0] + 0][pos[1] + 1] = 29;
        out_matrix[pos[0] + 0][pos[1] + 2] = 25;
        pos[1]                             = pos[1] + 3;
    }

    if (in_matrix [i] [j] == 30) //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 26;
        out_matrix[pos[0] + 1][pos[1] + 0] = 30;
        out_matrix[pos[0] + 2][pos[1] + 0] = 26;
        pos[1]                             = pos[1] + 1;
    }

    if (in_matrix[i][j] == 31) //ok
    {
        out_matrix[pos[0] + 0][pos[1] + 0] = 27;
        out_matrix[pos[0] + 0][pos[1] + 1] = 31;
        out_matrix[pos[0] + 0][pos[1] + 2] = 27;
        pos[1]                             = pos[1] + 3;
    }

    //adjust position

    if (pos[1] >= out_matrix.size())            // не конец строки
    {
        for (int i = 0; i < out_matrix.size(); i++)
        {
            if (out_matrix[i] [0] == -1)
            {
                pos[0] = i;
                break;
            }
        }
        pos[1] = 0;
        if (pos[0] >= out_matrix.size())
            std::cout << "error! no such row" << std::endl;
    }

    if (out_matrix [pos[0]] [pos[1]] == -1) //поднять если возможно
    {
        for (int i = 0; i < pos[0]; i++)
        {
            if (out_matrix[i] [pos[1]] == -1)
            {
                pos[0] = i;
                break;
            }
        }
    }
    if (out_matrix [pos[0]] [pos[1]] != -1) //опустить вниз если надо
    {
        for (int i = pos[0]; i < out_matrix.size(); i++)
        {
            if (out_matrix[i] [pos[1]] == -1)
            {
                pos[0] = i;
                break;
            }
        }
    }
}

void printMatrix(std::vector< std::vector<int> > &in_matrix)
{
    for (int i = 0; i < in_matrix.size(); i++)
    {
        for (int j = 0; j < in_matrix.size(); j++)
        {
            std::cout << in_matrix[i][j] << "	";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


bool getMartix(std::vector< std::vector<int> > &vec, std::ifstream& inputfile)
{
    // std::cout << "reading " << std::endl;
    int tmp;

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            if (inputfile >> tmp)
            {
                vec[i][j] = tmp;
            }
            else
            {
                // std::cout << "that's all!" << std::endl;
                return 0;
            }
        }
    }
    return 1;
}
bool getMartix_str_stolb(std::vector< std::vector<int> > &vec, std::ifstream& inputfile)
{
    // std::cout << "reading " << std::endl;
    int tmp;

    for (int j = 0; j < vec.size(); j++)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (inputfile >> tmp)
            {
                vec[i][j] = tmp;
            }
            else
            {
                // std::cout << "that's all!" << std::endl;
                return 0;
            }
        }
    }
    return 1;
}

void write_2dvector_to_js(std::vector< std::vector<int> > &vec, std::string& outputname)
{
    std::string buf = std::to_string(vec.size());

    outputname = outputname + "_side-" + buf + ".js";
    std::ofstream outputfile(outputname);
    if (outputfile.is_open())
        std::cout << outputname << " is open" << std::endl;
    else
    {
        std::cout << ">>>>>>> SHIT SHIT SHIT <<<<<<<" << std::endl;
    }

    outputfile << "var tilelist = [\n";

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            outputfile << vec[i][j];
            if ((i == (vec.size() - 1)) && (j == (vec.size() - 1)))
            {
                break;
            }
            outputfile << ",	";
        }
        outputfile << "\n";
    }
    outputfile << "\n];";


    outputfile.close();
}

void write_2dvector_to_file(std::vector< std::vector<int> > &vec, std::string& outputname)
{
    std::string buf = std::to_string(vec.size());

    outputname = outputname + buf + ".txt";
    std::ofstream outputfile(outputname);
    if (outputfile.is_open())
        std::cout << outputname << " is open" << std::endl;
    else
    {
        std::cout << ">>>>>>> SHIT SHIT SHIT <<<<<<<" << std::endl;
    }

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            outputfile << vec[i][j] << "  ";
        }
        outputfile << "\n";
    }

    outputfile.close();
}

int myPow(int x, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return x;

    int tmp = myPow(x, p / 2);
    if (p % 2 == 0)
        return tmp * tmp;
    else
        return x * tmp * tmp;
}

void addMatrixToFile(std::vector< std::vector<int> > &vec, std::ofstream& outputfile)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            outputfile << vec[i][j] << "  ";
        }
        outputfile << "\n";
    }

    outputfile << "\n";
}

void addMatrixToJsFile(std::vector< std::vector<int> > &vec, std::ofstream& outputfile)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            outputfile << vec[i][j] << ",  ";
        }
        outputfile << "\n";
    }

    outputfile << "\n";
}


void write_miniqs_to_js(std::vector< std::vector<int> > &vec, int n, int uniq_num)
{
    std::string   buf        = std::to_string(n);
    std::string   outputname = "miniqs";
    outputname = outputname + "_side-" + buf + ".js";
    std::ofstream outputfile(outputname);
    if (outputfile.is_open())
        std::cout << outputname << " is open" << std::endl;
    else
    {
        std::cout << ">>>>>>> SHIT SHIT SHIT <<<<<<<" << std::endl;
    }

    outputfile << "var tilelist = [\n";

    for (int i = 0; i < uniq_num; i++)
    {
        for (int j = 0; j < n * n; j++)
        {
            outputfile << vec[i][j];
            if ((i == (uniq_num - 1)) && (j == (n * n - 1)))
            {
                break;
            }
            outputfile << ",	";
        }
        outputfile << "\n";
    }
    outputfile << "\n];";


    outputfile.close();
}
void write_miniqs_to_txt(std::vector< std::vector<int> > &vec, int n, int uniq_num)
{
    std::string   buf        = std::to_string(n);
    std::string   outputname = "miniqs";
    outputname = outputname + "_side-" + buf + ".txt";
    std::ofstream outputfile(outputname);
    if (outputfile.is_open())
        std::cout << outputname << " is open" << std::endl;
    else
    {
        std::cout << ">>>>>>> SHIT SHIT SHIT <<<<<<<" << std::endl;
    }

    for (int i = 0; i < uniq_num; i++)
    {
        for (int j = 0; j < n * n; j++)
        {
            outputfile << vec[i][j]<< " ";
        }
        outputfile << "\n";
    }

    outputfile.close();
}


int howManyUniqs(std::vector<int> &minisq, std::vector< std::vector<int> > &all_minisquares, int num)
{
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        if (minisq == all_minisquares[i])
            count++;
    }
    return count;
}

bool isItNew(std::vector<int> &minisquare, std::vector< std::vector<int> > &uniq_minisquares, int uniq_num)
{
    if (uniq_num == 0)
        return 1;
    for (int i = 0; i < uniq_num; i++)
    {
        if (minisquare == uniq_minisquares[i])
            return 0;
    }
    return 1;
}


int findNewUniqs(std::vector< std::vector<int> > &uniq_minisquares, std::vector< std::vector<int> > &all_minisquares, int num, int uniq_num)
{
    // if (uniq_num != 0)
    //     uniq_num++;
		// std::cout << "uniqnum = "<< uniq_num << std::endl;
    int k   = 0;
    int tmp = 0;
		int new_uniqs=0;
    while (k < num)
    {
        //k = nextNew
        //uniq_count
        for (int j = k; j < num; j++)                 //найти следующий новый миник
        {
            if (isItNew(all_minisquares[j], uniq_minisquares, uniq_num) == 1)
            {
                k   = j;
                tmp = 0;
                break;
            }
            tmp = -1;
        }

        if (tmp == -1)
            break;
        //нашли следующий k
        // std::cout << "k = " << k << std::endl;
        uniq_minisquares[uniq_num] = all_minisquares[k];
        uniq_num++;
				new_uniqs++;
        k++;
    }
		// std::cout << "uniqnum = "<< uniq_num << std::endl;

		std::cout << "new guys = " << new_uniqs << std::endl;
    return new_uniqs;
}

void printVector(std::vector< std::vector<int> > &v, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << v[i][j] << "	";
        }
        std::cout << std::endl;
    }
}

int getMartices(std::vector< std::vector<int> > &all_minisquares, int n, int m, bool onemx)
{
    long unsigned int num = 0;
    int               tmp = 0;
    std::string       buf = std::to_string(m);
    m = myPow(2, m) - 1;

    typedef std::vector<int>   Row;
    typedef std::vector<Row>   Matrix;
    Matrix input_square_patch(m, Row(m));


    std::string   inputname = "super_order_" + buf + ".txt";
    std::ifstream inputfile(inputname);
    if (!inputfile.is_open())
        std::cout << "  cant open file" << std::endl;

    while (getMartix(input_square_patch, inputfile))
    {
        // printMatrix(input_square_patch);
        for (int i = 0; i < m - n + 1; i++)
        {
            for (int j = 0; j < m - n + 1; j++)
            {
                //
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < n; l++)
                    {
                        all_minisquares[num][tmp] = input_square_patch[i + k][j + l];
                        tmp++;
                        // uniq_minisquares[num].push_back(input_square_patch[i + k][j + l]);
                    }
                }
                tmp = 0;
                num++;
                //
            }
        }
        if (onemx == 1)
            break;
        // addMatrixToFile(input_square_patch, outputfile);
        // std::cout <<"num = "<< num << std::endl;
    }

    inputfile.close();

    return num;
}
