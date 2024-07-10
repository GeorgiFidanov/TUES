import React, { useState, useEffect } from 'react';
import "./Store.css";

function Products() {
 const [products, setProducts] = useState([]);
 const [currentPage, setCurrentPage] = useState(1);
 const [itemsPerPage, setItemsPerPage] = useState(12);
 const [sortType, setSortType] = useState('default');

 useEffect(() => {
    fetch('https://fakestoreapi.com/products')
      .then(res => res.json())
      .then(json => {
        setProducts(json);
      })
      .catch(error => {
        console.error('Error fetching products:', error);
      });
 }, []);

 useEffect(() => {
    if (sortType !== 'default') {
      sortProducts(sortType);
    }
 }, [sortType, products]); // Depend on sortType and products

 const indexOfLastItem = currentPage * itemsPerPage;
 const indexOfFirstItem = indexOfLastItem - itemsPerPage;
 let currentItems = products.slice(indexOfFirstItem, indexOfLastItem);

 const paginate = (pageNumber) => setCurrentPage(pageNumber);

 const sortProducts = (type) => {
    let sortedProducts = [...products];
    switch (type) {
      case 'price_asc':
        sortedProducts.sort((a, b) => a.price - b.price);
        break;
      case 'price_desc':
        sortedProducts.sort((a, b) => b.price - a.price);
        break;
      case 'rating_asc':
        sortedProducts.sort((a, b) => a.rating - b.rating);
        break;
      case 'rating_desc':
        sortedProducts.sort((a, b) => b.rating - a.rating);
        break;
      case 'title_asc':
        sortedProducts.sort((a, b) => a.title.localeCompare(b.title));
        break;
      default:
        break;
    }
    setProducts(sortedProducts);
 };

 return (
    <div>
      <select onChange={(e) => setSortType(e.target.value)}>
        <option value="default">Default</option>
        <option value="price_asc">Price Ascending</option>
        <option value="price_desc">Price Descending</option>
        <option value="rating_asc">Rating Ascending</option>
        <option value="rating_desc">Rating Descending</option>
        <option value="title_asc">Title Ascending</option>
      </select>
      <select onChange={(e) => setItemsPerPage(parseInt(e.target.value, 10))}>
        <option value="12">12</option>
        <option value="24">24</option>
        <option value="36">36</option>
      </select>
      {currentItems.map(product => (
        <div className="productBox" key={product.id}>
          <h2 className='title'>{product.title}</h2>
          <p className='desc'>{product.rating.rate}</p>
          <p className='desc'>Price: {product.price}</p>
          <p className='desc'>Description: {product.description}</p>
          <img className="img" src={product.image} alt={product.title}></img>
        </div>
      ))}
      <div className="pagination">
        {[...Array(Math.ceil(products.length / itemsPerPage)).keys()].map(number => (
          <button key={number + 1} onClick={() => paginate(number + 1)}>
            {number + 1}
          </button>
        ))}
      </div>
    </div>
 );
}

function App() {
 return (
    <div className='App'>
      <Products />
    </div>
 );
}

export default App;
