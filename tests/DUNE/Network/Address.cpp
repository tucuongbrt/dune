//***************************************************************************
// Copyright 2007-2016 Universidade do Porto - Faculdade de Engenharia      *
// Laboratório de Sistemas e Tecnologia Subaquática (LSTS)                  *
//***************************************************************************
// This file is part of DUNE: Unified Navigation Environment.               *
//                                                                          *
// Commercial Licence Usage                                                 *
// Licencees holding valid commercial DUNE licences may use this file in    *
// accordance with the commercial licence agreement provided with the       *
// Software or, alternatively, in accordance with the terms contained in a  *
// written agreement between you and Universidade do Porto. For licensing   *
// terms, conditions, and further information contact lsts@fe.up.pt.        *
//                                                                          *
// European Union Public Licence - EUPL v.1.1 Usage                         *
// Alternatively, this file may be used under the terms of the EUPL,        *
// Version 1.1 only (the "Licence"), appearing in the file LICENCE.md       *
// included in the packaging of this file. You may not use this work        *
// except in compliance with the Licence. Unless required by applicable     *
// law or agreed to in writing, software distributed under the Licence is   *
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF     *
// ANY KIND, either express or implied. See the Licence for the specific    *
// language governing permissions and limitations at                        *
// http://ec.europa.eu/idabc/eupl.html.                                     *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************

// ISO C++ 98 headers.
#include <iostream>

// DUNE headers.
#include <DUNE/Network.hpp>

// Catch headers.
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace DUNE::Network;

TEST_CASE("any")
{
  Address a = Address::Any;
  REQUIRE(a.str() == "0.0.0.0");
}

TEST_CASE("loopback")
{
  Address a = Address::Loopback;
  REQUIRE(a.str() == "127.0.0.1");
}

TEST_CASE("broadcast")
{
  Address a = Address::Broadcast;
  REQUIRE(a.str() == "255.255.255.255");
}

TEST_CASE("equals")
{
  Address a = "140.130.23.1";
  Address b = a;
  REQUIRE(a == b);
}

TEST_CASE("nativeInteger")
{
  Address a = "140.130.23.1";
  Address b = a.toIntegerNative();
  REQUIRE(a == b);
}

TEST_CASE("resolveFail")
{
  Address a = "xxxwwwxxxx.com";
  REQUIRE_FALSE(a.resolve());
}

TEST_CASE("resolveIp")
{
  Address a = "192.168.106.1";
  REQUIRE(a.resolve());
}