// Day01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
--- Day 1: Historian Hysteria ---
The Chief Historian is always present for the big Christmas sleigh launch, but nobody has seen him in months! Last anyone heard, he was visiting locations that are historically significant to the North Pole; a group of Senior Historians has asked you to accompany them as they check the places they think he was most likely to visit.

As each location is checked, they will mark it on their list with a star. They figure the Chief Historian must be in one of the first fifty places they'll look, so in order to save Christmas, you need to help them get fifty stars on their list before Santa takes off on December 25th.

Collect stars by solving puzzles. Two puzzles will be made available on each day in the Advent calendar; the second puzzle is unlocked when you complete the first. Each puzzle grants one star. Good luck!

You haven't even left yet and the group of Elvish Senior Historians has already hit a problem: their list of locations to check is currently empty. Eventually, someone decides that the best place to check first would be the Chief Historian's office.

Upon pouring into the office, everyone confirms that the Chief Historian is indeed nowhere to be found. Instead, the Elves discover an assortment of notes and lists of historically significant locations! This seems to be the planning the Chief Historian was doing before he left. Perhaps these notes can be used to determine which locations to search?

Throughout the Chief's office, the historically significant locations are listed not by name but by a unique number called the location ID. To make sure they don't miss anything, The Historians split into two groups, each searching the office and trying to create their own complete list of location IDs.

There's just one problem: by holding the two lists up side by side (your puzzle input), it quickly becomes clear that the lists aren't very similar. Maybe you can help The Historians reconcile their lists?

For example:

3   4
4   3
2   5
1   3
3   9
3   3
Maybe the lists are only off by a small amount! To find out, pair up the numbers and measure how far apart they are. Pair up the smallest number in the left list with the smallest number in the right list, then the second-smallest left number with the second-smallest right number, and so on.

Within each pair, figure out how far apart the two numbers are; you'll need to add up all of those distances. For example, if you pair up a 3 from the left list with a 7 from the right list, the distance apart is 4; if you pair up a 9 with a 3, the distance apart is 6.

In the example list above, the pairs and distances would be as follows:

The smallest number in the left list is 1, and the smallest number in the right list is 3. The distance between them is 2.
The second-smallest number in the left list is 2, and the second-smallest number in the right list is another 3. The distance between them is 1.
The third-smallest number in both lists is 3, so the distance between them is 0.
The next numbers to pair up are 3 and 4, a distance of 1.
The fifth-smallest numbers in each list are 3 and 5, a distance of 2.
Finally, the largest number in the left list is 4, while the largest number in the right list is 9; these are a distance 5 apart.
To find the total distance between the left list and the right list, add up the distances between all of the pairs you found. In the example above, this is 2 + 1 + 0 + 1 + 2 + 5, a total distance of 11!

Your actual left and right lists contain many location IDs. What is the total distance between your lists?

Your puzzle answer was 1879048.

--- Part Two ---
Your analysis only confirmed what everyone feared: the two lists of location IDs are indeed very different.

Or are they?

The Historians can't agree on which group made the mistakes or how to read most of the Chief's handwriting, but in the commotion you notice an interesting detail: a lot of location IDs appear in both lists! Maybe the other numbers aren't location IDs at all but rather misinterpreted handwriting.

This time, you'll need to figure out exactly how often each number from the left list appears in the right list. Calculate a total similarity score by adding up each number in the left list after multiplying it by the number of times that number appears in the right list.

Here are the same example lists again:

3   4
4   3
2   5
1   3
3   9
3   3
For these example lists, here is the process of finding the similarity score:

The first number in the left list is 3. It appears in the right list three times, so the similarity score increases by 3 * 3 = 9.
The second number in the left list is 4. It appears in the right list once, so the similarity score increases by 4 * 1 = 4.
The third number in the left list is 2. It does not appear in the right list, so the similarity score does not increase (2 * 0 = 0).
The fourth number, 1, also does not appear in the right list.
The fifth number, 3, appears in the right list three times; the similarity score increases by 9.
The last number, 3, appears in the right list three times; the similarity score again increases by 9.
So, for these example lists, the similarity score at the end of this process is 31 (9 + 4 + 0 + 0 + 9 + 9).

Once again consider your left and right lists. What is their similarity score?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

static void printSummation(const std::vector<int>& number, const std::string& msg)
{
	int summation = 0;
	for (int i = 0; i < number.size(); i++)
	{
		summation += number[i];
	}

	std::cout << msg << " : " << summation << std::endl;
}

static int distance(const int& a, const int& b)
{
	if (a >= b)
	{
		return a - b;
	}
	return b - a;
}

static int findSimilarity(const int& number, const std::vector<int>& right)
{
	int similarity = 0;
	for (int j = 0; j < right.size(); j++)
	{
		if (number == right[j])
		{
			similarity++;
		}
		else if (number < right[j])
		{
			return similarity;
		}
	}
	return similarity;
}

static void printSumOfDistances(const std::vector<int>& left, const std::vector<int>& right)
{
	std::vector<int> distances;
	for (int i = 0; i < left.size(); i++)
	{
		distances.push_back(distance(left[i], right[i]));
	}
	printSummation(distances, "The total distance is");
}

static void printSimilaryityScore(const std::vector<int>& left, const std::vector<int>& right)
{
	std::vector<int> similarityScore;
	for (int i = 0; i < left.size(); i++)
	{
		similarityScore.push_back(left[i] * findSimilarity(left[i], right));
	}
	printSummation(similarityScore, "The total similarity score is");
}

int main()
{
	std::vector<int> left = {
		69214,
		83241,
		37930,
		50722,
		93164,
		80918,
		17490,
		64372,
		89659,
		91555,
		48924,
		38031,
		57853,
		88521,
		68331,
		32767,
		95030,
		80448,
		27268,
		18742,
		50258,
		88830,
		73007,
		95145,
		58976,
		22476,
		21785,
		21560,
		82909,
		55371,
		73607,
		88276,
		86274,
		61163,
		52231,
		84647,
		37515,
		44394,
		58258,
		56060,
		79808,
		96748,
		87301,
		93991,
		45674,
		10870,
		13175,
		12881,
		11425,
		71044,
		70247,
		97814,
		78003,
		45779,
		95915,
		51055,
		14500,
		40956,
		64791,
		95406,
		18800,
		85004,
		16723,
		14333,
		40419,
		81499,
		31696,
		71897,
		63928,
		46875,
		40086,
		67622,
		63819,
		74694,
		63615,
		88828,
		58917,
		86066,
		84677,
		87339,
		30182,
		71811,
		26364,
		45435,
		65473,
		40764,
		86131,
		46984,
		94658,
		34864,
		74271,
		37126,
		26701,
		11846,
		91698,
		19986,
		31279,
		25542,
		43023,
		25001,
		39137,
		75796,
		93491,
		16837,
		78167,
		56738,
		66303,
		91100,
		99100,
		46126,
		31826,
		61208,
		98875,
		89960,
		87445,
		90701,
		48604,
		49830,
		32422,
		48321,
		91545,
		30591,
		76791,
		47653,
		70447,
		96337,
		40822,
		50985,
		45600,
		78539,
		11792,
		89999,
		22229,
		79514,
		93645,
		39916,
		63722,
		85209,
		78460,
		79669,
		89396,
		12518,
		70992,
		92482,
		50977,
		59666,
		69358,
		30774,
		50495,
		74843,
		64043,
		42690,
		95474,
		31999,
		77935,
		86471,
		82671,
		21996,
		25301,
		45903,
		88433,
		18897,
		23742,
		29440,
		77679,
		67503,
		22862,
		68125,
		32102,
		57298,
		44985,
		76984,
		96974,
		22496,
		19906,
		53085,
		49762,
		23508,
		73366,
		39420,
		21487,
		49538,
		58985,
		78834,
		83207,
		26624,
		33276,
		62119,
		72488,
		69108,
		28383,
		45283,
		56242,
		47120,
		20917,
		91088,
		30625,
		81302,
		14883,
		45215,
		36185,
		47369,
		39320,
		35775,
		20573,
		92168,
		85925,
		83017,
		88673,
		85790,
		40389,
		13925,
		65265,
		21058,
		81605,
		49669,
		58410,
		20993,
		89320,
		93679,
		24396,
		26960,
		35749,
		67814,
		95966,
		45832,
		21396,
		70924,
		51921,
		86430,
		60703,
		55109,
		64568,
		61181,
		76019,
		93405,
		40732,
		27676,
		46615,
		94412,
		42651,
		22911,
		37891,
		39505,
		30551,
		52001,
		94890,
		12845,
		60037,
		17811,
		39461,
		70835,
		26239,
		21199,
		29427,
		99745,
		58368,
		32844,
		25356,
		55087,
		73711,
		23878,
		19011,
		55522,
		25442,
		43553,
		79059,
		45546,
		18253,
		13486,
		85621,
		94812,
		35976,
		95446,
		68679,
		35048,
		32404,
		54639,
		46890,
		54797,
		58043,
		38310,
		96824,
		82010,
		44558,
		25947,
		39754,
		85172,
		38409,
		93847,
		70670,
		66466,
		14378,
		10594,
		88488,
		80919,
		15539,
		76757,
		73014,
		10103,
		63011,
		97931,
		11511,
		90999,
		10581,
		24639,
		12573,
		94628,
		68709,
		69611,
		77840,
		56046,
		64975,
		35086,
		21044,
		27003,
		99990,
		92558,
		10676,
		79869,
		41478,
		40010,
		57724,
		36886,
		52799,
		74618,
		37677,
		25056,
		37249,
		16420,
		92579,
		32467,
		50446,
		20800,
		25367,
		20200,
		67153,
		99387,
		99003,
		21079,
		21496,
		10244,
		60317,
		89792,
		66971,
		48409,
		87836,
		94588,
		19574,
		43975,
		54578,
		24412,
		66935,
		75103,
		99675,
		63283,
		38622,
		76156,
		18868,
		95097,
		87940,
		31588,
		86721,
		40662,
		61441,
		95742,
		12500,
		69704,
		52150,
		94648,
		34905,
		90241,
		22820,
		84893,
		35291,
		91607,
		91250,
		12934,
		50355,
		11918,
		11981,
		90011,
		19160,
		38536,
		47433,
		71173,
		58871,
		99297,
		14256,
		42700,
		65952,
		38344,
		31939,
		88319,
		48532,
		54160,
		51367,
		63774,
		91398,
		19606,
		15722,
		11670,
		11752,
		57229,
		92900,
		35472,
		11762,
		52327,
		49806,
		83152,
		66672,
		13349,
		10860,
		34902,
		36500,
		90699,
		65392,
		67360,
		20770,
		27579,
		52424,
		88044,
		82234,
		38116,
		71095,
		35234,
		74397,
		59605,
		33516,
		83961,
		17934,
		58619,
		24784,
		60415,
		33999,
		70899,
		71992,
		31607,
		82993,
		98377,
		19236,
		69248,
		12305,
		12750,
		67143,
		51085,
		21283,
		58438,
		61450,
		77223,
		40730,
		61388,
		10697,
		29817,
		44526,
		42126,
		91131,
		53762,
		99711,
		41168,
		89661,
		19509,
		46491,
		82876,
		57530,
		30070,
		37182,
		98660,
		53088,
		23056,
		59488,
		27659,
		85486,
		33558,
		64995,
		58406,
		52353,
		52674,
		97158,
		36966,
		96617,
		17881,
		38135,
		35640,
		75976,
		54361,
		70827,
		23840,
		93190,
		75051,
		64409,
		20040,
		92938,
		43465,
		11298,
		99421,
		21674,
		68613,
		40038,
		90984,
		72223,
		99618,
		96274,
		54840,
		77678,
		79087,
		27866,
		94127,
		83829,
		21118,
		54767,
		31592,
		84251,
		16359,
		33404,
		30167,
		54633,
		64214,
		65936,
		26779,
		56981,
		88384,
		16954,
		19265,
		20882,
		24268,
		73896,
		17491,
		34135,
		97863,
		33458,
		87234,
		17021,
		43735,
		41413,
		23370,
		40859,
		20847,
		78780,
		89412,
		44732,
		15416,
		20026,
		20447,
		92208,
		22919,
		19025,
		78537,
		21990,
		57022,
		23379,
		10223,
		70096,
		27889,
		73766,
		17352,
		18766,
		85353,
		16699,
		18043,
		67635,
		89066,
		96095,
		80193,
		83111,
		82714,
		15568,
		46071,
		24766,
		24252,
		90799,
		45593,
		42434,
		76708,
		44049,
		26070,
		89487,
		75405,
		61151,
		55659,
		97690,
		23955,
		51413,
		93303,
		88340,
		36666,
		68983,
		97452,
		77775,
		93498,
		35180,
		88369,
		60950,
		80469,
		44830,
		56953,
		14598,
		48010,
		51318,
		70157,
		29536,
		97148,
		88940,
		94267,
		80689,
		51360,
		22949,
		61037,
		12068,
		29715,
		90504,
		31564,
		33933,
		29523,
		77893,
		55688,
		24079,
		13322,
		89943,
		29072,
		53586,
		23918,
		56128,
		66658,
		10133,
		99815,
		68216,
		46022,
		83063,
		62075,
		53883,
		66467,
		47896,
		71785,
		84153,
		29778,
		31766,
		16108,
		45369,
		40723,
		65628,
		22238,
		91501,
		17080,
		27106,
		52006,
		10554,
		42902,
		78074,
		76079,
		66574,
		30704,
		61970,
		75806,
		65083,
		44142,
		89309,
		14755,
		31582,
		71879,
		50300,
		55843,
		70241,
		13864,
		56863,
		28825,
		93845,
		20530,
		44137,
		47611,
		76632,
		96396,
		21784,
		10465,
		76247,
		90281,
		68036,
		98495,
		66489,
		73992,
		27262,
		46644,
		27046,
		68306,
		56759,
		59597,
		35807,
		81247,
		28886,
		93602,
		28876,
		83548,
		42548,
		17737,
		39564,
		38730,
		15305,
		64475,
		88203,
		49209,
		58403,
		33211,
		12588,
		38930,
		57720,
		70408,
		35638,
		97473,
		79297,
		82229,
		86569,
		25113,
		16476,
		75345,
		15696,
		24138,
		82572,
		88539,
		59729,
		20283,
		31336,
		93878,
		69846,
		54419,
		82798,
		49394,
		69345,
		39250,
		26399,
		32384,
		97484,
		63090,
		76597,
		14020,
		62045,
		18689,
		52623,
		52491,
		87906,
		82114,
		26961,
		17367,
		98279,
		71505,
		19537,
		21670,
		56125,
		60764,
		77962,
		91463,
		47556,
		83067,
		55521,
		51846,
		34746,
		41554,
		87263,
		22625,
		44644,
		66676,
		10499,
		70675,
		40581,
		87994,
		94436,
		97737,
		79484,
		53333,
		42911,
		37210,
		12286,
		86302,
		89841,
		79773,
		91417,
		61800,
		23495,
		31663,
		26644,
		46904,
		26299,
		81023,
		20782,
		48451,
		42895,
		53844,
		49912,
		86234,
		98733,
		90395,
		87860,
		62319,
		81832,
		96801,
		34060,
		19206,
		61175,
		38749,
		35243,
		94052,
		68544,
		38895,
		13279,
		47468,
		94318,
		71918,
		86789,
		83931,
		71126,
		16125,
		39086,
		16328,
		71229,
		79671,
		91145,
		53528,
		23966,
		36677,
		77291,
		32335,
		94998,
		16372,
		99014,
		61040,
		93576,
		92791,
		79499,
		71009,
		16657,
		75219,
		49208,
		65336,
		39833,
		39788,
		15097,
		13674,
		35721,
		46963,
		90463,
		78488,
		78916,
		59443,
		43680,
		36601,
		41176,
		43717,
		37766,
		82109,
		17559,
		28284,
		22341,
		31223,
		39647,
		64525,
		29368,
		98386,
		64817,
		46178,
		95082,
		70089,
		72539,
		11579,
		63864,
		13611,
		71054,
		49549,
		98626,
		21372,
		42043,
		51898,
		29323,
		64305,
		70362,
		26501,
		10172,
		19438,
		17316,
		13127,
		11331,
		37354,
		34872,
		48467,
		36745,
		97478,
		29324,
		24179,
		24371,
		61932,
		55020,
		64150,
		68372,
		10714,
		68990,
		72825,
		85765,
		32558,
		78846,
		71711,
		90337,
		32298,
		86944,
		36174,
		53613,
		79549,
		43539,
		61122,
		30084,
		49969,
		38272,
		11594,
		69508,
		21588,
		97316,
		97425,
		62763,
		63345,
		43015,
		52670,
		58251,
		33771,
		12901,
		42101,
		43970,
		90983,
		33538,
		89043,
		65451,
		73769,
		78129,
		84083,
		72978,
		81230,
		97477,
		96888,
		24917,
		97486,
		13312,
		27167,
		76762,
		72850,
		24623,
		99735,
		92737,
		33120,
		63398,
		38385,
		81987,
		62260,
		67235,
		85100,
		27762,
		13906,
		85558,
		42148,
		88468,
		92033,
		39309,
		99521,
		80929,
		28236,
		83442,
		50329,
		75224,
		71764,
		22012,
		89620,
		60052,
		98379,
		47207,
		47361,
		96159,
		61549,
		36863,
		28638,
		28879,
		24022,
		25334,
		25095,
		14190,
		66088,
		36470,
		47970,
		35396,
		24123,
		26462,
		49162,
		88098,
		53920,
		84177,
		18969,
		55280,
		14058,
		13245,
		23434,
		56966,
		77060,
		25997,
		41947,
		52576,
		91921
	};

	std::vector<int> right = {
	   60950,
	   49638,
	   31308,
	   94914,
	   82798,
	   72850,
	   79421,
	   87820,
	   98375,
	   95812,
	   93602,
	   64096,
	   20530,
	   43214,
	   14770,
	   19574,
	   92579,
	   10870,
	   86384,
	   65926,
	   95193,
	   17352,
	   82798,
	   42403,
	   17352,
	   68379,
	   17811,
	   90827,
	   37527,
	   69778,
	   32404,
	   44965,
	   46099,
	   63445,
	   27046,
	   20530,
	   57298,
	   99003,
	   74954,
	   34105,
	   73814,
	   51318,
	   46022,
	   44642,
	   96969,
	   49159,
	   23840,
	   86704,
	   89064,
	   92543,
	   88369,
	   73317,
	   44160,
	   14598,
	   46875,
	   99003,
	   19574,
	   23840,
	   99735,
	   51318,
	   72878,
	   33238,
	   31504,
	   69398,
	   10870,
	   79136,
	   24276,
	   55421,
	   46875,
	   33198,
	   76959,
	   29550,
	   88369,
	   35769,
	   20200,
	   58414,
	   20414,
	   24696,
	   47814,
	   89616,
	   36007,
	   63762,
	   18927,
	   54026,
	   83062,
	   12795,
	   19574,
	   71532,
	   36666,
	   85172,
	   85172,
	   63381,
	   91608,
	   99003,
	   44394,
	   17352,
	   82252,
	   10870,
	   98869,
	   25208,
	   44758,
	   94436,
	   42015,
	   69895,
	   59486,
	   17811,
	   49575,
	   33987,
	   41554,
	   41472,
	   20530,
	   20200,
	   49776,
	   23840,
	   88369,
	   59605,
	   24766,
	   60581,
	   32404,
	   49338,
	   51318,
	   23840,
	   25366,
	   64300,
	   10870,
	   10870,
	   99003,
	   36666,
	   58520,
	   21021,
	   39770,
	   23840,
	   24252,
	   31414,
	   99874,
	   12567,
	   87301,
	   12845,
	   94436,
	   33420,
	   36762,
	   91072,
	   20530,
	   51318,
	   39809,
	   93602,
	   24889,
	   85209,
	   88117,
	   68135,
	   93602,
	   14598,
	   99003,
	   10870,
	   30381,
	   46022,
	   23840,
	   17352,
	   68950,
	   49209,
	   15186,
	   13349,
	   38006,
	   44394,
	   19534,
	   19006,
	   87523,
	   36752,
	   85209,
	   32444,
	   10870,
	   88369,
	   44648,
	   17352,
	   88369,
	   69481,
	   39320,
	   13349,
	   19574,
	   85172,
	   20200,
	   31279,
	   33747,
	   86304,
	   77460,
	   39320,
	   87130,
	   15410,
	   72850,
	   46022,
	   64125,
	   60950,
	   88580,
	   46022,
	   12845,
	   67959,
	   92579,
	   98117,
	   22568,
	   46818,
	   72873,
	   19661,
	   48658,
	   60950,
	   66758,
	   46875,
	   23570,
	   28941,
	   62352,
	   46022,
	   17811,
	   14598,
	   98819,
	   70060,
	   36401,
	   63107,
	   60950,
	   32404,
	   36606,
	   89908,
	   66724,
	   82887,
	   98507,
	   60950,
	   99777,
	   90281,
	   69067,
	   77174,
	   31279,
	   41554,
	   76733,
	   86032,
	   34984,
	   39320,
	   80530,
	   35718,
	   73310,
	   56302,
	   12644,
	   32659,
	   46875,
	   88369,
	   61401,
	   19574,
	   99381,
	   99003,
	   77236,
	   10870,
	   99735,
	   93480,
	   52563,
	   99003,
	   32404,
	   53413,
	   61865,
	   52578,
	   85172,
	   17811,
	   61341,
	   39124,
	   94153,
	   15193,
	   15821,
	   76895,
	   85172,
	   23840,
	   51318,
	   85172,
	   46875,
	   98333,
	   78640,
	   14598,
	   22851,
	   35811,
	   86540,
	   32404,
	   58367,
	   82218,
	   99735,
	   64140,
	   28678,
	   78102,
	   19574,
	   90281,
	   88560,
	   55410,
	   90281,
	   77816,
	   72850,
	   79705,
	   31866,
	   72850,
	   85172,
	   82798,
	   36494,
	   90281,
	   60764,
	   20530,
	   80854,
	   28777,
	   51318,
	   72850,
	   23511,
	   46778,
	   17352,
	   84344,
	   87301,
	   73454,
	   60950,
	   36666,
	   32404,
	   43452,
	   36666,
	   27046,
	   63339,
	   32404,
	   41554,
	   76384,
	   51318,
	   34929,
	   23840,
	   17811,
	   13349,
	   20530,
	   39658,
	   28890,
	   39602,
	   19780,
	   60950,
	   21533,
	   91814,
	   76018,
	   40645,
	   27046,
	   93602,
	   50429,
	   82421,
	   85172,
	   99003,
	   68678,
	   45196,
	   85172,
	   96967,
	   64416,
	   28760,
	   49209,
	   13036,
	   25049,
	   80163,
	   90281,
	   22870,
	   17352,
	   85209,
	   46748,
	   13318,
	   86570,
	   17811,
	   12554,
	   31279,
	   28731,
	   25307,
	   20683,
	   51679,
	   60665,
	   46875,
	   96428,
	   48663,
	   83722,
	   52130,
	   71064,
	   72850,
	   81541,
	   88917,
	   82798,
	   13349,
	   69674,
	   89186,
	   76205,
	   10870,
	   93561,
	   87504,
	   97792,
	   99003,
	   95219,
	   72254,
	   20241,
	   49592,
	   46875,
	   36666,
	   92579,
	   26453,
	   17352,
	   66675,
	   31279,
	   69055,
	   37364,
	   98234,
	   67948,
	   52760,
	   98639,
	   27046,
	   27046,
	   90281,
	   24766,
	   82069,
	   17352,
	   10464,
	   51318,
	   24252,
	   27046,
	   11070,
	   20530,
	   67520,
	   74641,
	   14208,
	   24766,
	   68056,
	   23840,
	   12845,
	   17811,
	   20530,
	   70562,
	   32404,
	   23840,
	   60884,
	   10870,
	   36937,
	   79377,
	   82798,
	   17811,
	   81965,
	   60950,
	   46183,
	   32404,
	   62356,
	   42550,
	   61565,
	   48168,
	   27705,
	   72447,
	   97390,
	   97543,
	   39320,
	   72850,
	   47302,
	   13713,
	   84586,
	   20530,
	   84960,
	   87301,
	   18648,
	   92620,
	   95051,
	   46022,
	   85172,
	   23970,
	   24766,
	   23485,
	   24766,
	   12845,
	   97679,
	   87301,
	   87301,
	   90281,
	   99003,
	   12845,
	   33467,
	   94041,
	   49209,
	   33662,
	   88369,
	   76043,
	   46875,
	   87301,
	   54418,
	   20530,
	   12845,
	   84792,
	   41554,
	   65903,
	   15049,
	   23393,
	   27655,
	   10870,
	   78468,
	   85172,
	   74733,
	   16180,
	   51318,
	   18196,
	   85172,
	   48165,
	   97826,
	   51609,
	   78526,
	   92903,
	   62444,
	   17352,
	   68779,
	   49209,
	   99735,
	   84903,
	   37409,
	   85533,
	   96379,
	   33036,
	   23840,
	   87366,
	   46731,
	   27046,
	   58444,
	   39320,
	   80340,
	   47980,
	   86692,
	   53720,
	   57298,
	   85172,
	   94436,
	   72257,
	   16995,
	   14598,
	   12845,
	   34877,
	   10870,
	   37193,
	   73107,
	   64788,
	   96478,
	   20530,
	   41554,
	   13349,
	   43950,
	   46022,
	   51318,
	   27518,
	   52659,
	   55643,
	   46875,
	   44659,
	   85942,
	   41554,
	   13573,
	   20530,
	   27046,
	   47883,
	   66716,
	   94436,
	   13835,
	   47578,
	   27046,
	   40352,
	   99003,
	   86884,
	   50077,
	   59737,
	   53132,
	   82798,
	   76756,
	   80464,
	   32404,
	   32404,
	   36666,
	   17352,
	   24567,
	   51318,
	   62699,
	   88369,
	   17393,
	   51318,
	   65043,
	   42548,
	   88369,
	   19788,
	   17352,
	   23840,
	   60950,
	   50409,
	   50949,
	   87976,
	   10769,
	   41554,
	   44394,
	   74623,
	   46875,
	   86119,
	   36666,
	   18100,
	   28288,
	   85175,
	   73788,
	   40289,
	   89290,
	   99735,
	   26094,
	   12845,
	   32404,
	   43254,
	   16119,
	   59605,
	   27046,
	   24766,
	   99003,
	   12845,
	   82798,
	   63373,
	   85172,
	   87301,
	   65294,
	   85209,
	   28648,
	   88812,
	   82995,
	   72320,
	   80865,
	   78887,
	   24766,
	   32095,
	   48334,
	   58704,
	   12845,
	   14598,
	   88548,
	   69626,
	   67845,
	   85172,
	   99003,
	   15395,
	   21232,
	   23840,
	   14598,
	   32404,
	   69944,
	   51318,
	   16006,
	   85209,
	   24766,
	   35318,
	   94436,
	   88485,
	   31279,
	   45332,
	   92579,
	   83343,
	   17811,
	   13517,
	   96843,
	   54855,
	   59112,
	   19574,
	   37842,
	   87301,
	   72591,
	   89415,
	   36666,
	   88369,
	   18398,
	   24252,
	   10397,
	   12845,
	   19574,
	   62837,
	   67656,
	   12845,
	   36666,
	   19574,
	   22897,
	   17811,
	   13349,
	   49209,
	   71061,
	   85003,
	   28828,
	   28473,
	   12845,
	   62295,
	   85383,
	   49331,
	   17352,
	   89989,
	   24766,
	   88369,
	   58715,
	   32404,
	   84611,
	   99003,
	   11412,
	   66456,
	   94970,
	   74875,
	   50501,
	   98501,
	   74927,
	   60997,
	   95234,
	   39320,
	   62977,
	   20570,
	   27046,
	   46875,
	   94223,
	   79621,
	   80687,
	   17322,
	   87301,
	   29585,
	   23840,
	   19574,
	   10870,
	   27046,
	   17352,
	   78295,
	   24791,
	   94436,
	   12845,
	   49905,
	   27046,
	   39320,
	   87301,
	   39331,
	   21205,
	   31692,
	   72850,
	   91006,
	   84255,
	   40818,
	   52987,
	   60950,
	   87538,
	   19159,
	   43143,
	   32208,
	   23840,
	   32404,
	   75497,
	   32404,
	   31279,
	   98683,
	   85172,
	   99003,
	   70112,
	   46022,
	   88369,
	   25937,
	   25375,
	   28451,
	   19574,
	   46875,
	   17811,
	   54069,
	   59029,
	   87301,
	   80404,
	   52594,
	   10952,
	   91631,
	   59965,
	   42548,
	   80377,
	   31212,
	   11321,
	   99003,
	   51732,
	   39961,
	   46875,
	   62666,
	   41644,
	   41554,
	   19574,
	   96788,
	   93469,
	   78835,
	   90378,
	   45455,
	   19811,
	   38053,
	   95310,
	   12652,
	   88369,
	   97345,
	   32404,
	   72850,
	   94436,
	   85172,
	   83143,
	   46875,
	   17811,
	   53747,
	   85172,
	   51318,
	   36666,
	   36666,
	   87028,
	   48785,
	   94915,
	   46022,
	   74300,
	   61982,
	   89642,
	   22838,
	   23840,
	   31279,
	   49209,
	   46826,
	   87301,
	   17811,
	   41554,
	   71452,
	   88369,
	   55867,
	   95213,
	   12845,
	   20530,
	   67001,
	   23840,
	   48955,
	   39867,
	   77019,
	   20530,
	   93201,
	   17586,
	   41181,
	   80727,
	   99055,
	   82718,
	   61735,
	   80967,
	   12845,
	   20530,
	   41824,
	   87301,
	   94436,
	   67725,
	   22450,
	   96722,
	   82562,
	   69206,
	   17811,
	   24766,
	   41554,
	   60727,
	   90281,
	   13349,
	   60950,
	   94271,
	   80804,
	   20530,
	   88369,
	   32947,
	   49209,
	   88369,
	   60082,
	   82580,
	   13349,
	   12845,
	   28932,
	   77829,
	   39365,
	   92579,
	   81861,
	   51350,
	   42548,
	   77114,
	   87301,
	   84124,
	   56474,
	   76586,
	   87832,
	   32404,
	   88369,
	   22433,
	   30520,
	   18267,
	   73191,
	   41554,
	   36666,
	   20200,
	   51318,
	   23840,
	   22773,
	   20249,
	   85209,
	   10870,
	   88369,
	   10246,
	   63888,
	   39320,
	   45220,
	   10320,
	   36160,
	   52644,
	   64027,
	   57768,
	   40811,
	   77880,
	   20200,
	   93936,
	   85172,
	   94436,
	   76808,
	   38430,
	   29108,
	   72165,
	   43129,
	   44170,
	   88369,
	   56992,
	   39320,
	   86708,
	   30429,
	   70293,
	   68766,
	   76575,
	   41520,
	   31254,
	   23840,
	   93602,
	   82798,
	   48255,
	   20530,
	   25496,
	   41554,
	   67658,
	   88369,
	   93514,
	   26380,
	   82798,
	   28981,
	   70224,
	   78572,
	   28610,
	   47914,
	   75916,
	   42548,
	   39320,
	   78173,
	   51318,
	   93602,
	   20600,
	   47594,
	   58718,
	   87301,
	   39670,
	   59605,
	   20200,
	   98299,
	   53969,
	   51318,
	   63713,
	   42047,
	   90281,
	   51318,
	   36666,
	   12845,
	   20200,
	   32404,
	   32404,
	   99391,
	   17352,
	   46875,
	   20530,
	   10870,
	   47197,
	   99003,
	   82219,
	   28881,
	   88379,
	   44694,
	   94436,
	   40762,
	   17352,
	   84760,
	   80773,
	   90281,
	   24766,
	   55460,
	   10870,
	   46875,
	   63285,
	   70993,
	   50008,
	   87301,
	   17811,
	   47037,
	   52299,
	   12845,
	   87301,
	   59862,
	   10870,
	   36666,
	   11340,
	   68145,
	   14598,
	   46622,
	   78829,
	   71967,
	   57796,
	   82348,
	   12845,
	   51318
	};

	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	printSumOfDistances(left, right);
	printSimilaryityScore(left, right);

	// printSumOfDistances sorted = 1879048
	// printSimilaryityScore = 21024792

	return 0;
}
