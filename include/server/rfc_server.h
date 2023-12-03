/*
** EPITECH PROJECT, 2023
** rfc.h
** File description:
** rfc
*/

#pragma once

#include <stdio.h>

#define SEND(sock, message) (void)dprintf((sock), (message))

typedef struct rfc_s {
    const int code;
    const char *response;
} rfc_t;

static const char R100[] = "[100]\r\n";
static const char R210[] = "[210][%s|%s]\r\n";
static const char R220[] = "[220][%s|%s]\r\n";
static const char R230[] = "[230][%s|%s]\r\n";
static const char R240[] = "[240][%s|%s]\r\n";
static const char R250[] = "[250][%s|%s|%s]\r\n";
static const char R255[] = "[255][%s|%s|%s]\r\n";
static const char R260[] = "[260][%s|%s|%s]\r\n";
static const char R265[] = "[265][%s|%s|%s]\r\n";
static const char R270[] = "[270][%s|%s|%s|%s|%s]\r\n";
static const char R275[] = "[275][%s|%s|%s|%s|%s]\r\n";
static const char R280[] = "[280][%s|%s|%s|%s]\r\n";
static const char R285[] = "[285][%s|%s|%s|%s]\r\n";
static const char R290[] = "[290][%s|%s]\r\n";
static const char R300[] = "[300][%s|%s|%s]\r\n";
static const char R310[] = "[310][%s|%s|%s]\r\n";
static const char R320[] = "[320][%s|%s|%s]\r\n";
static const char R330[] = "[330][%s|%s|%s|%s|%s]\r\n";
static const char R333[] = "[333]\r\n";
static const char R336[] = "[336]\r\n";
static const char R339[] = "[339]\r\n";
static const char R340[] = "[340][%s|%s|%s]\r\n";
static const char R350[] = "[350][%s|%s|%s]\r\n";
static const char R360[] = "[360][%s|%s|%s]\r\n";
static const char R370[] = "[370][%s|%s|%s|%s|%s]\r\n";
static const char R380[] = "[380][%s|%s|%s|%s]\r\n";
static const char R390[] = "[390][%s|%s|%s]\r\n";
static const char R400[] = "[400][%s]\r\n";
static const char R410[] = "[410][%s]\r\n";
static const char R420[] = "[420][%s]\r\n";
static const char R430[] = "[430][%s]\r\n";
static const char R450[] = "[450]\r\n";
static const char R455[] = "[455]\r\n";
static const char R460[] = "[460]\r\n";
static const char R470[] = "[470]\r\n";
static const char R480[] = "[480]\r\n";
static const char R490[] = "[490]\r\n";
static const char R495[] = "[495]\r\n";
static const char R500[] = "[500]\r\n";
static const char R510[] = "[510]\r\n";
static const char R520[] = "[520]\r\n";
static const char R530[] = "[530]\r\n";

static const rfc_t RFC_100 = {100, R100};
static const rfc_t RFC_210 = {210, R210};
static const rfc_t RFC_220 = {220, R220};
static const rfc_t RFC_230 = {230, R230};
static const rfc_t RFC_240 = {240, R240};
static const rfc_t RFC_250 = {250, R250};
static const rfc_t RFC_255 = {255, R255};
static const rfc_t RFC_260 = {260, R260};
static const rfc_t RFC_265 = {265, R265};
static const rfc_t RFC_270 = {270, R270};
static const rfc_t RFC_275 = {275, R275};
static const rfc_t RFC_280 = {280, R280};
static const rfc_t RFC_285 = {285, R285};
static const rfc_t RFC_290 = {290, R290};
static const rfc_t RFC_300 = {300, R300};
static const rfc_t RFC_310 = {310, R310};
static const rfc_t RFC_320 = {320, R320};
static const rfc_t RFC_330 = {330, R330};
static const rfc_t RFC_333 = {333, R333};
static const rfc_t RFC_336 = {336, R336};
static const rfc_t RFC_339 = {339, R339};
static const rfc_t RFC_340 = {340, R340};
static const rfc_t RFC_350 = {350, R350};
static const rfc_t RFC_360 = {360, R360};
static const rfc_t RFC_370 = {370, R370};
static const rfc_t RFC_380 = {380, R380};
static const rfc_t RFC_390 = {390, R390};
static const rfc_t RFC_400 = {400, R400};
static const rfc_t RFC_410 = {410, R410};
static const rfc_t RFC_420 = {420, R420};
static const rfc_t RFC_430 = {430, R430};
static const rfc_t RFC_450 = {450, R450};
static const rfc_t RFC_455 = {450, R455};
static const rfc_t RFC_460 = {460, R460};
static const rfc_t RFC_470 = {470, R470};
static const rfc_t RFC_480 = {480, R480};
static const rfc_t RFC_490 = {490, R490};
static const rfc_t RFC_495 = {490, R495};
static const rfc_t RFC_500 = {500, R500};
static const rfc_t RFC_510 = {510, R510};
static const rfc_t RFC_520 = {520, R520};
static const rfc_t RFC_530 = {530, R530};
