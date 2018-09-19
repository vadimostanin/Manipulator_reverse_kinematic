/*
 * DerivativeFunctions.h
 *
 *  Created on: Dec 15, 2017
 *      Author: user
 */

#ifndef DERIVATIVEFUNCTIONS_H_
#define DERIVATIVEFUNCTIONS_H_

#include <vector>

class DerivativeFunctions
{
public:

	static double derivative_XY_1_Legs_0( const std::vector<double> & params );
	static double derivative_XZ_1_Legs_0( const std::vector<double> & params );

	static double derivative_XY_2_Legs_0( const std::vector<double> & params );
	static double derivative_XY_2_Legs_1( const std::vector<double> & params );
	static double derivative_XZ_2_Legs_0( const std::vector<double> & params );
	static double derivative_XZ_2_Legs_1( const std::vector<double> & params );

	static double derivative_XY_3_Legs_0( const std::vector<double> & params );
	static double derivative_XY_3_Legs_1( const std::vector<double> & params );
	static double derivative_XY_3_Legs_2( const std::vector<double> & params );
	static double derivative_XZ_3_Legs_0( const std::vector<double> & params );
	static double derivative_XZ_3_Legs_1( const std::vector<double> & params );
	static double derivative_XZ_3_Legs_2( const std::vector<double> & params );

	static double derivative_XY_4_Legs_0( const std::vector<double> & params );
	static double derivative_XY_4_Legs_1( const std::vector<double> & params );
	static double derivative_XY_4_Legs_2( const std::vector<double> & params );
	static double derivative_XY_4_Legs_3( const std::vector<double> & params );
	static double derivative_XZ_4_Legs_0( const std::vector<double> & params );
	static double derivative_XZ_4_Legs_1( const std::vector<double> & params );
	static double derivative_XZ_4_Legs_2( const std::vector<double> & params );
	static double derivative_XZ_4_Legs_3( const std::vector<double> & params );

	static double derivative_XY_5_Legs_0( const std::vector<double> & params );
	static double derivative_XY_5_Legs_1( const std::vector<double> & params );
	static double derivative_XY_5_Legs_2( const std::vector<double> & params );
	static double derivative_XY_5_Legs_3( const std::vector<double> & params );
	static double derivative_XY_5_Legs_4( const std::vector<double> & params );
	static double derivative_XZ_5_Legs_0( const std::vector<double> & params );
	static double derivative_XZ_5_Legs_1( const std::vector<double> & params );
	static double derivative_XZ_5_Legs_2( const std::vector<double> & params );
	static double derivative_XZ_5_Legs_3( const std::vector<double> & params );
	static double derivative_XZ_5_Legs_4( const std::vector<double> & params );


	static double derivative_XY_10_Legs_0( const std::vector<double> & params );
	static double derivative_XY_10_Legs_1( const std::vector<double> & params );
	static double derivative_XY_10_Legs_2( const std::vector<double> & params );
	static double derivative_XY_10_Legs_3( const std::vector<double> & params );
	static double derivative_XY_10_Legs_4( const std::vector<double> & params );
	static double derivative_XY_10_Legs_5( const std::vector<double> & params );
	static double derivative_XY_10_Legs_6( const std::vector<double> & params );
	static double derivative_XY_10_Legs_7( const std::vector<double> & params );
	static double derivative_XY_10_Legs_8( const std::vector<double> & params );
	static double derivative_XY_10_Legs_9( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_0( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_1( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_2( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_3( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_4( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_5( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_6( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_7( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_8( const std::vector<double> & params );
	static double derivative_XZ_10_Legs_9( const std::vector<double> & params );
};

#endif /* DERIVATIVEFUNCTIONS_H_ */
