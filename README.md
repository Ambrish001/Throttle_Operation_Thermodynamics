# Throttle_Operation_Thermodynamics

Coding Exercise: Throttle Operation Thermodynamics
Problem Statement
Throttle is an important component of refrigeration cycle wherein it allows a means of reducing
the temperature of working fluid. For the present problem, consider a n-butane stream at
pressure 𝑃! and temperature 𝑇! that is throttled to a final pressure 𝑃". The temperature (𝑇") or
the quality (vapor mole fraction: 𝑥" ≡ 𝑥") of the exit stream are unknown.
#Model the throttle process as a steady-state, steady-flow adiabatic operation with no moving parts. 
Further, you can ignore kinetic energy and potential energy changes for the flow streams.
With these assumptions, the general energy balance simplifies to: Δ𝐻!" = 0.
Task
Develop a code in language/library of your choice (C, Matlab, Python, etc.) to answer question
given below. The solution approach has been discussed in the class. Test cases can be taken
from the lecture class.
1. Determine the phase of the exit stream: subcooled liquid, liquid-vapor
coexistence, superheated vapor.
2. Determine the temperature (𝑇") of the exit stream. Further, in case the exit
stream phase is liquid-vapor coexistence, also determine its quality, 𝑥".
3. Some refrigeration cycle operations involve replacement of a throttle valve
by an expander device with work output (e.g., turbine). Determine the maximum work
that can be obtained on adiabatic expansion of the same inlet stream (𝑃!, 𝑇!) to the same
outlet pressure (𝑃").
Note: Maximum work (= Δ𝐻!") will be obtained for adiabatic, reversible expansion:
Δ𝑆!" = 0.
Parameter values
𝑃! (𝑖𝑛 MPa): {1.4, 1.6}; 𝑇! (in K): {200, 400}; 𝑃" = 0.1 MPa
Thermophysical properties of n-butane: tabulated data for isobars at 0.1, 1.4, 1.6 MPa given in
excel sheet. Use linear interpolation in 𝑃, 𝑇 to get a value at any given state poin.
Input parameters (𝑃!, 𝑇!) should be defined such that their value can be provided at time
of execution without need to recompile the code. You can either use an input file
(preferable) or take input from command line.
Answer to Q1-3 can be printed to an output file or displayed on command line.




The code is the solution to this problem.
