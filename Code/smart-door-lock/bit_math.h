/*
 * bit_math.h
 *
 * Created: 27/11/2022 12:40:33 pm
 *  Author: Loay
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG, PIN)       (REG |= (1<<PIN))
#define CLEAR_BIT(REG, PIN)     (REG &= ~(1<<PIN))
#define TOGGLE_BIT(REG, PIN)    (REG ^= (1<<PIN))
#define READ_BIT(REG, PIN)      ((REG >> PIN) & 1)




#endif /* BIT_MATH_H_ */