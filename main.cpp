#include "algorithm/greedy_unique_source_files_constructor.h"
#include "helpers.h"
#include "input_parser.h"
#include "source_file.h"
#include <algorithm/closest_compilation_start_constructor.h>
#include <algorithm/complex_constructor.h>
#include <algorithm/cost_functions/least_target_dependants_cost.h>
#include <algorithm/cost_functions/most_dependencies_cost.h>
#include <algorithm/grasp.h>
#include <algorithm/least_busy_server_constructor.h>
#include <algorithm>
#include <iostream>
#include <server.h>
#include <solution.h>

void printSourceFiles(vector<SourceFilePtr> &sourceFiles) {
  for (auto &sourceFile : sourceFiles) {
    cout << *sourceFile << endl;
  }

  cout << endl;
}

void printInputInfos(InputMetadata &inputMetadata) {
  cout << "Total Files: " << inputMetadata.filesCount << endl;
  cout << "Target Files: " << inputMetadata.targetsCount << endl;
  cout << "Servers: " << inputMetadata.serversCount << endl;
}

void printResults(Solution &solution) {
  //    cout << solution;
  cout << "TOTAL SCORE = " << solution.score() << endl;
}

Problem parseSourceFilesFromFile(string filePath, InputMetadata &outMetadata) {
  InputParser inputParser(filePath);
  vector<ServerPtr> servers;
  auto sourceFiles = inputParser.parse(outMetadata);

  for (int i = 0; i < outMetadata.serversCount; ++i) {
    servers.push_back(ServerPtr(new Server(i)));
  }

  return Problem({sourceFiles, servers});
}

int main(int argc, char *argv[]) {
  const char *inputFilePath = argv[1];

  InputMetadata inputMetadata;
  auto problem = parseSourceFilesFromFile(inputFilePath, inputMetadata);

  printInputInfos(inputMetadata);
  //    printSourceFiles(problem.sourceFiles);

  const int greedyConstructorsCount = 5;

  string greedyConstructorNames[greedyConstructorsCount]{
      "MostTargetDependantsConstructor",
      "ClosestCompilationStartConstructor",
      "LeastBusyServerConstructor",
      "GreedyUniqueSourceFilesConstructor",
      "ComplexConstructor",
  };

  shared_ptr<GreedyConstructor> greedyConstructors[greedyConstructorsCount] = {
      shared_ptr<GreedyConstructor>(new LeastBusyServerConstructor(make_shared<LeastTargetDependantsCost>())),
      shared_ptr<GreedyConstructor>(new ClosestCompilationStartConstructor(make_shared<MostDependenciesCost>())),
      shared_ptr<GreedyConstructor>(new LeastBusyServerConstructor(make_shared<MostDependenciesCost>())),
      shared_ptr<GreedyConstructor>(new GreedyUniqueSourceFilesConstructor(make_shared<LeastTargetDependantsCost>())),
      shared_ptr<GreedyConstructor>(new ComplexConstructor(make_shared<MostDependenciesCost>()))};

  for (int i = 3; i < greedyConstructorsCount - 1; ++i) {
    string greedyConstructorName = greedyConstructorNames[i];
    auto greedyConstructor = greedyConstructors[i];
    auto problem = parseSourceFilesFromFile(inputFilePath, inputMetadata);

    cout << "Running with " + greedyConstructorName + " constructor" << endl;

    Grasp grasp(problem, *greedyConstructor, 100);
    unique_ptr<Solution> solution;

    int execTime = measureBlockExecution("Grasp Construction Performance",
                                         [&solution, grasp]() mutable { solution = grasp.perform(); });

    printResults(*solution);
    cout << "Execution time: " << execTime << endl;
  }

  return 0;
}
