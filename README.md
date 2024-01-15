# Design Space Exploration Project

## Overview
This project, titled "Finding Optimal Hardware Configurations by Employing a Heuristics-Based Approach," focuses on exploring an 18-dimensional processor pipeline and memory hierarchy design space using SimpleScalar. The project emphasizes heuristic-based approaches to optimize performance (ED^2P) and energy efficiency (EDP), and defending the choices made in the exploration process.

## Key Components
- **Heuristic Search Functions**: Custom algorithms to explore design spaces efficiently.
- **Performance and Energy Efficiency**: Optimization of designs for best performance and energy efficiency.
- **SimpleScalar Integration**: Use of SimpleScalar as the evaluation engine.
- **Validation and Analysis**: In-depth validation of configurations and detailed analysis of results.

## Files Description
- `431project.cpp`, `431project.h`, `431projectUtils.cpp`: Core project files integrating with SimpleScalar.
- `YOURCODEHERE.cpp`: Custom code modifications for heuristic search functions.
- `Makefile`: Build settings for the project.
- `runprojectsuite.sh`: Shell script for executing design space exploration using SimpleScalar with specified configurations.
- `Project-Report.pdf`: Comprehensive report discussing the project's heuristic approach, methodology, and findings.

## Script Overview: runprojectsuite.sh
This script automates the execution of SimpleScalar for design space exploration. It runs the SimpleScalar tool with a variety of configuration parameters based on an 18-dimensional design space. The script uses arrays to define different parameters and iterates through them to test various combinations. Outputs are saved in a specified directory for analysis.


## Report Highlights
- **Configuration Validation Function**: Ensures compatibility of parameter combinations.
- **Heuristic Development**: Strategies for optimizing performance and energy efficiency.
- **Results and Analysis**: Detailed analysis of the explored configurations, including graphical representations.
- **Best Design Points**: Discussion on the most effective configurations for performance and efficiency.
- **Conclusion**: Summarizes the effectiveness of the Configuration Validation Function and the Heuristic Search Function in the design space exploration.

## Design Space Dimensions
Refer to [`DesignSpaceDimensionChart.pdf`]() for detailed explanation of each index in the 18-dimensional design space, covering various processor and memory hierarchy configurations.


## Acknowledgments
Special thanks to the providers of the framework code and SimpleScalar tool which were instrumental in this project. The comprehensive exploration and heuristic approaches were made possible by these foundational tools.

## Installation and Execution
* Clone or download the GitHub repository.
* Run the makefile in a linux environment.
* Make sure that all the provided code files are in the same directory.

## Contribution
This project is part of an educational assignment. External contributions are not applicable, but discussions and insights are welcome.

## License
No licenses

For more information or queries, please contact my [`email`](keshu.13579@gmail.com).

## References
- SimpleScalar documentation and resources.

