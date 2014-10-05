/* Copyright (c) 2014 Francois Doray <francois.pierre-doray@polymtl.ca>
 *
 * This file is part of tibeecompare.
 *
 * tibeecompare is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tibeecompare is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tibeecompare.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <iostream>
#include <boost/program_options.hpp>
#include <base/print.hpp>

#include "Arguments.hpp"
#include "TibeeCompare.hpp"
#include "ex/InvalidArgument.hpp"


using tibee::base::tberror;
using tibee::base::tbendl;

namespace
{

/**
 * Parses the command line arguments passed to the program.
 *
 * @param argc Number of arguments in \p argv
 * @param argv Command line arguments
 * @param args Arguments values to fill
 *
 * @returns    0 to continue, 1 if there's a command line error
 */
int parseOptions(int argc, char* argv[], tibeecompare::Arguments& args)
{
    namespace bpo = boost::program_options;

    bpo::options_description desc;

    desc.add_options()
        ("help,h", "help")
        ("trace,t", bpo::value<std::vector<std::string>>())
        ("verbose,v", bpo::bool_switch()->default_value(false))
    ;

    bpo::variables_map vm;

    try {
        auto cliParser = bpo::command_line_parser(argc, argv);
        auto parsedOptions = cliParser.options(desc).run();

        bpo::store(parsedOptions, vm);
    } catch (const std::exception& ex) {
        tberror() << "command line error: " << ex.what() << tbendl();
        return 1;
    }

    if (!vm["help"].empty()) {
        std::cout <<
            "usage: " << argv[0] << " [options]" << std::endl <<
            std::endl <<
            "options:" << std::endl <<
            std::endl <<
            "  -h, --help                  print this help message" << std::endl <<
            "  -a                          path of the trace" << std::endl <<
            "  -v, --verbose               verbose" << std::endl;

        return -1;
    }

    try {
        vm.notify();
    } catch (const std::exception& ex) {
        tberror() << "command line error: " << ex.what() << tbendl();
        return 1;
    }

    // trace
    if (vm["trace"].empty()) {
        tberror() << "No trace specified." << tbendl();
        return 1;
    }
    args.traces = vm["trace"].as<std::vector<std::string>>();

    // verbose
    args.verbose = vm["verbose"].as<bool>();

    return 0;
}

}

int main(int argc, char* argv[])
{
    tibeecompare::Arguments args;

    int ret = parseOptions(argc, argv, args);

    if (ret < 0) {
        return 0;
    } else if (ret > 0) {
        return ret;
    }

    // create a TibeeCompare instance and run it.
    try {
        std::unique_ptr<tibeecompare::TibeeCompare> tibeeCompare {
            new tibeecompare::TibeeCompare {args}};
        return tibeeCompare->run() ? 0 : 1;
    } catch (const tibeecompare::ex::InvalidArgument& ex) {
        tberror() << "invalid argument: " << ex.what() << tbendl();
    } catch (const std::exception& ex) {
        tberror() << "unknown error: " << ex.what() << tbendl();
    }

    return 1;
}