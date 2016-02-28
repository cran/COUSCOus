\name{COUSCOus}
\title{
Contact prediction using shrinked covariance.
}
\alias{COUSCOus}
\description{
COUSCOus is a residue-residue contact detecting method.
}
\usage{
COUSCOus(fasta.file, verbose = TRUE)
}
\arguments{
  \item{fasta.file}{
  Protein sequence alignment file name in FASTA format.
%%     ~~Describe \code{fasta.file} here~~
}
  \item{verbose}{
  Print tracing information. The default value is TRUE.
%%     ~~Describe \code{verbose} here~~
}
}
\details{
Contact prediction using shrinked covariance (COUSCOus). COUSCOus is a residue-residue contact detecting method approaching the contact inference using the glassofast implementation of Matyas and Sustik (2012, The University of Texas at Austin UTCS Technical Report 2012:1-3. TR-12-29.) that solves the L_1 regularised Gaussian maximum likelihood estimation of the inverse of a covariance matrix. Prior to the inverse covariance matrix estimation we utilise a covariance matrix shrinkage approach, the empirical Bayes covariance estimator, which has been shown by Haff (1980) <DOI:10.1214/aos/1176345010> to be the best estimator in a Bayesian framework, especially dominating estimators of the form aS, such as the smoothed covariance estimator applied in a related contact inference technique PSICOV.
%%  ~~ If necessary, more details than the description above ~~
}
\value{
A data frame with 3 columns (i, j, pCorr) containing all possible pairs of residues along with their COUSCOus correlation value.
%%  ~Describe the value returned
%%  If it is a LIST, use
%%  \item{comp1 }{Description of 'comp1'}
%%  \item{comp2 }{Description of 'comp2'}
%% ...
}
\author{
Reda Rawi, Matyas A. Sustik, Ben Calderhead \cr
Maintainer: Reda Rawi <rrawi@qf.org.qa>
%%  ~~who you are~~
}
\examples{
# Alignment file
file.fasta <- system.file( "examples/1oaiA0.fa", package = "COUSCOus" )

# Run COUSCOus
df.predictions <- COUSCOus( file.fasta )
}
