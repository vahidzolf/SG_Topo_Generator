 
Smart Grid communication networks is a heterogeneous network consists of PLC Nodes and Wireless nodes, 
which reside in substations in power grid. An example of generated topology is shown at below:
 
 
PLC nodes are smart meters and Wireless Nodes are Wireless access points in a wireless mesh network, which is installed in substations in a city. 
This script first places smart meters according to a minimum and maximum Threshold between smart meters. Then using an Integer Linear Programming model places the wireless nodes to provide the best connectivity between PLC nodes. SCIP optimization suite is used to solve the optimization model. 

# SG_Topo_Generator

A topology generator for a heterogeneous Smart Grid communication networks

Smart Grid communication networks is a heterogeneous network consists of PLC Nodes and Wireless nodes, 
which reside in substations in power grid. An example of generated topology is shown at below:
 
 

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

You need to install scip optimization suite through [scip website](http://scip.zib.de/#download)

### Installing

You need to run main.sc with the following command to run the process :  

```
sudo bash main.sc
```

## Built With

* [Scip Optimization suite](http://scip.zib.de/#download) - An open source ILP solver. 


## Contributing

If you are interested to contribute drop me an email through vahid.zolfaghari@aut.ac.ir



## Authors

* **Vahid Zolfaghari** - *Initial work* - [Ceit Website](ceit.aut.ac.ir/~zolfaghari)

## License

This project is licensed under the MIT License

## Acknowledgments
 I want to Thank [Dr Masoud Shokrnezhad](https://www.linkedin.com/in/masoud-shokrnezhad-7851a5111/) 
