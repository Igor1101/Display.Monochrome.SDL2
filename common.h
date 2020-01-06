/*
 * common.h
 *
 *  Created on: Jan 6, 2020
 *      Author: igor
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <cstdio>

#define pr_err(...)  fprintf(stderr, __VA_ARGS__); puts("")
#define pr_info(...)  fprintf(stdout, __VA_ARGS__); puts("")
#ifdef DEBUG
#define pr_debug(...)  fprintf(stdout, __VA_ARGS__); puts("")
#else
#define pr_debug(...)
#endif

#endif /* COMMON_H_ */
